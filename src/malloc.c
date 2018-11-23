/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_block	*get_unallocated_block(t_block *head, size_t size)
{
	t_block	*block;

	block = head;
	while (block && (block->allocated ||
	block->size < size - BLOCK_SIZE))
		block = block->next;
	return (block);
}

static t_block		*extend_zone(size_t size, t_block *zone)
{
	t_block	*block;

	block = zone;
	while (block && block->next)
		block = block->next;
	block->next = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
		-1, 0);
	block->next->size = size;
	block->next->allocated = 0;
	block->next->next = NULL;
	return (block->next);
}

static int		create_block(size_t size, t_block *block)
{
	t_block	*tmp;
	size_t	next_size;

	if (!block || block->allocated)
		return(0);
	tmp = block->next;
	block->next = (void*)block + size;
	if ((next_size = block->size - size) == 0)
		block->next = tmp;
	else
	{
		block->next->size = block->size - size;
		block->next->next = tmp;
		block->size = size - BLOCK_SIZE;
		block->allocated = 1;
	}
	return (1);
}

static t_block	*map_management(size_t size, t_block *zone, short flag)
{
	t_block	*block;

	if (zone == NULL)
		return (NULL);
	if ((block = get_unallocated_block(zone, size)) == NULL)
	{
		if (flag & OPT_TINY)
			block = extend_zone(TINY_MIN, zone);
		if (flag & OPT_SMALL)
			block = extend_zone(SMALL_MIN, zone);
		if (flag & OPT_LARGE)
			block = extend_zone(size, zone);
	}
	if (!create_block(size, block))
		return (NULL);
	return(BLOCK_DATA(block));
}

static void		*ft_malloc(size_t size)
{
	t_block	*block;

	if (IS_TINY(size))
		return ((block = map_management(size, get_mem()->tiny, OPT_TINY))
		== NULL ? NULL : block);
	else if (IS_SMALL(size))
		return ((block = map_management(size, get_mem()->small, OPT_SMALL))
		== NULL ? NULL : block);
	else if (IS_LARGE(size))
		return ((block = map_management(size, get_mem()->large, OPT_LARGE))
		== NULL ? NULL : block);
	else
		return (NULL);
}

void 			*malloc(size_t size)
{
	void	*ptr;

	if (size < 1)
		return (NULL);
	if (pthread_mutex_lock(&g_mutex) != 0)
		return (NULL);
	ptr = ft_malloc(ALIGN(size + BLOCK_SIZE));
	if (pthread_mutex_unlock(&g_mutex) != 0)
		return (NULL);
	return (ptr);
}