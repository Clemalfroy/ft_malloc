/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:11:03 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/08/23 20:08:37 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_block	*extend_large_zone(size_t size, t_block *b, t_block *last)
{
	while (b && b->next)
	{
		last = b;
		b = b->next;
	}
	if (b == last)
	{
		b->next = mmap(0, size + BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_ANON \
			| MAP_PRIVATE, -1, 0);
		get_mem()->large = b->next;
		b->next->size = size;
		b->next->is_free = 0;
		b->next->next = b;
		b->next = NULL;
		return (get_mem()->large);
	}
	b->next = mmap(0, size + BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | \
		MAP_PRIVATE, -1, 0);
	last->next = b->next;
	b->next->size = size;
	b->next->is_free = 0;
	b->next->next = b;
	b->next = NULL;
	return (last->next);
}

static void		extend_zone(t_block *zone, size_t size)
{
	t_block	*b;

	b = zone;
	while (b && b->next)
		b = b->next;
	b->next = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, \
		-1, 0);
	b->next->size = size - BLOCK_SIZE;
	b->next->is_free = 1;
	b->next->next = NULL;
}

static t_block	*find_free_block(t_block *zone, size_t size)
{
	t_block	*b;

	b = zone;
	while (b && !(b->is_free && b->size >= size + BLOCK_SIZE))
		b = b->next;
	return (b);
}

static t_block	*manage_map(size_t size, t_block *zone)
{
	t_block	*b;

	if ((b = find_free_block(zone, size)) == NULL)
	{
		if (size + BLOCK_SIZE <= TINY)
		{
			extend_zone(zone, TINY);
			return (manage_map(size, zone));
		}
		else
		{
			extend_zone(zone, SMALL);
			return (manage_map(size, zone));
		}
	}
	else
		split_block(b, size);
	return (b);
}

void			*malloc(size_t size)
{
	size_t	s;
	t_block	*b;

	pthread_mutex_lock(get_lock());
	s = ALLIGN4(size);
	if (s + BLOCK_SIZE * 2 <= TINY)
		b = manage_map(s, get_mem()->tiny);
	else if (s + BLOCK_SIZE * 2 <= SMALL)
		b = manage_map(s, get_mem()->small);
	else
		b = extend_large_zone(s, get_mem()->large, get_mem()->large);
	pthread_mutex_unlock(get_lock());
	return (BLOCK_DATA(b));
}
