/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data	*get_mem()
{
	if (g_mem != NULL)
		return (g_mem);
	if ((g_mem = mmap(0, sizeof(t_data), PROT_READ | PROT_WRITE, MAP_ANON |
		MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	if ((g_mem->tiny = mmap(0, TINY_MIN, PROT_READ | PROT_WRITE, MAP_ANON |
		MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	if ((g_mem->small = mmap(0, SMALL_MIN, PROT_READ | PROT_WRITE, MAP_ANON |
		MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	if ((g_mem->large = mmap(0, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_ANON |
		MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	if ((void *)g_mem->tiny == (void*)SIZE_MAX || (void *)g_mem->small ==
		(void*)SIZE_MAX || (void *)g_mem->large == (void*)SIZE_MAX)
		return (NULL);
	ft_memset(g_mem->tiny, 0, BLOCK_SIZE);
	ft_memset(g_mem->small, 0, BLOCK_SIZE);
	ft_memset(g_mem->large, 0, BLOCK_SIZE);
	g_mem->tiny->size = TINY_MIN - BLOCK_SIZE;
	g_mem->small->size = SMALL_MIN - BLOCK_SIZE;
	return (g_mem);
}