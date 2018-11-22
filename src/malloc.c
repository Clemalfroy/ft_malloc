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

void		*ft_alloc(size_t size) {
	void *map;

	if ((map = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON |MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	return (map);
}

void 		*malloc(size_t size)
{
	if (size < 1)
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	pthread_mutex_unlock(&g_mutex);

	return (NULL);
}