/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:32:58 by bdurst            #+#    #+#             */
/*   Updated: 2022/05/27 12:32:58 by bdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = 0;
	if (s && f)
	{
		while (s[i])
			f(&(s[i++]));
	}
}
