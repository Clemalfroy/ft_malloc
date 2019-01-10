/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 23:27:23 by cmalfroy          #+#    #+#             */
/*   Updated: 2018/08/23 17:43:29 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_mem			*g_base = NULL;
static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t	*get_lock(void)
{
	return (&g_mutex);
}

t_mem			*get_mem(void)
{
	if (g_base == NULL)
	{
		g_base = mmap(0, sizeof(t_mem), PROT_READ | PROT_WRITE, MAP_ANON | \
			MAP_PRIVATE, -1, 0);
		g_base->tiny = mmap(0, TINY_MIN, PROT_READ | PROT_WRITE, MAP_ANON | \
			MAP_PRIVATE, -1, 0);
		if ((void*)g_base->tiny == (void*)SIZE_MAX)
			exit(1);
		g_base->tiny->size = TINY_MIN - BLOCK_SIZE;
		g_base->tiny->is_free = 1;
		g_base->tiny->next = NULL;
		g_base->small = mmap(0, SMALL_MIN, PROT_READ | PROT_WRITE, MAP_ANON | \
			MAP_PRIVATE, -1, 0);
		if ((void*)g_base->small == (void*)SIZE_MAX)
			exit(1);
		g_base->small->size = SMALL_MIN - BLOCK_SIZE;
		g_base->small->is_free = 1;
		g_base->small->next = NULL;
		g_base->large = mmap(0, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | \
			MAP_PRIVATE, -1, 0);
		g_base->large->size = 0;
		g_base->large->is_free = 1;
		g_base->large->next = NULL;
	}
	return (g_base);
}

void			split_block(t_block *b, size_t size)
{
	t_block	*save;

	save = b->next;
	b->next = (void*)b + BLOCK_SIZE + size;
	b->next->is_free = 1;
	b->next->size = b->size - BLOCK_SIZE - size;
	b->next->next = save;
	b->is_free = 0;
	b->size = size;
}

t_block			*find_ptr(t_block *b, void *ptr)
{
	while (b)
	{
		if ((void*)b + BLOCK_SIZE == ptr)
			return (b);
		b = b->next;
	}
	return (NULL);
}
