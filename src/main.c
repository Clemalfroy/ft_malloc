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

#include <stdio.h>
#include <assert.h>

int			main()
{
    char *str;

    str = malloc(sizeof(char)*5);
    str[0] = 'a';
    str[1] = 'v';
    str[2] = 'd';
    str[3] = 'e';
    str[4] = '\0';
    ft_putf(1, "Test1: %s\n", str);
    ft_puts(1, "Malloc(0): ");
    malloc(0) == NULL ? ft_puts(1, "Success\n") :ft_puts(1, "Failed\n");
    ft_puts(1, "Malloc(1): ");
    malloc(1) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(11): ");
    malloc(11) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(111): ");
    malloc(111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(1111): ");
    malloc(1111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(11111): ");
    malloc(11111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(111111): ");
    malloc(111111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(1111111): ");
    malloc(1111111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(11111111): ");
    malloc(11111111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    ft_puts(1, "Malloc(111111111): ");
    malloc(111111111) == NULL ? ft_puts(1, "Failed\n") :ft_puts(1, "Success\n");
    show_alloc_mem();
	return (0);
}
