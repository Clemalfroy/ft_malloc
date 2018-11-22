/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showallocmem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void        show_alloc_mem()
{
    pthread_mutex_lock(&g_mutex);
    //TODO: CODE HERE
	pthread_mutex_unlock(&g_mutex);
}
