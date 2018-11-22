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
	block->size < size))
		block = block->next;
	return (block);
}

static t_block	*map_management(size_t size, t_block *zone, short flag)
{
	t_block	*block;

	if (zone == NULL)
		return NULL;
	if ((block = get_unallocated_block(zone, size)) == NULL)
	{
		if (flag & OPT_TINY) {}
			//extend tiny
		if (flag & OPT_SMALL) {}
			//extend small
		if (flag & OPT_LARGE) {}
			//extend large
	}

	//Split block

	return(BLOCK_DATA(block));
}

static void		*ft_malloc(size_t size)
{
	t_block	*block;

	if (IS_TINY(size))
		return ((block = map_management(size, get_mem()->tiny, OPT_TINY)) == NULL
		? NULL : block);
	else if (IS_SMALL(size))
		return ((block = map_management(size, get_mem()->small, OPT_SMALL)) == NULL
		? NULL : block);
	else if (IS_LARGE(size))
		return ((block = map_management(size, get_mem()->large, OPT_LARGE)) == NULL
		? NULL : block);
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