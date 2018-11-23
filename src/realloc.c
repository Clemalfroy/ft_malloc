/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void *ft_realloc(void *ptr, size_t size)
{
    t_block *block;

    (void)ptr;
    (void)size;
    (void)block;
    return (void *)1;
}

void 		*realloc(void *ptr, size_t size)
{
    void *ret;

    if (size < 1)
        return (NULL);
    if (!ptr)
        return (malloc(size));
    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (pthread_mutex_lock(&g_mutex) != 0)
		return (NULL);
	ret = ft_realloc(ptr, size);
	if (pthread_mutex_unlock(&g_mutex) != 0)
		return (NULL);      
    return (void*)1;
}