/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelpp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:50:56 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/08/10 03:28:55 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "io.h"

void	ft_strdelpp(char ***str)
{
	int		i;
	char	**tmp;

	tmp = *str;
	i = -1;
	while (tmp[++i])
		ft_strdel(&(tmp[i]));
	free(*str);
	*str = NULL;
}
