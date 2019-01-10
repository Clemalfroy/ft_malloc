/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counttab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:39:15 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/10/11 13:39:22 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_counttab(char **tabu)
{
	size_t		count;

	count = 0;
	while (tabu[count])
		++count;
	return (count);
}
