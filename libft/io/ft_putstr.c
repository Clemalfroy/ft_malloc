/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurst <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:32:55 by bdurst            #+#    #+#             */
/*   Updated: 2022/05/27 12:32:55 by bdurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_putstr(const char *s)
{
	ft_fputstr(s, 1);
}
