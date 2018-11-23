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

static void print_hex(long nb, char first)
{
	if (first)
		ft_puts(1,"0x");
	if (nb >= 16)
		print_hex(nb / 16, 0);
	if (nb % 16 < 10)
		ft_putc(1, (char)(((nb % 16) + 48)));
	else
		ft_putc(1, (char)((nb % 16) + 55));
}

static void print_nb(long nb)
{
	if (nb >= 10)
		print_nb(nb / 10);
	ft_putc(1, (char)(48 + (nb % 10)));
}

static long	print_block(t_block *b)
{
	long	total;

	total = 0;
	while (b)
	{
		print_hex((long)((BLOCK_DATA(b))), 1);
		ft_puts(1," - ");
		print_hex((long)((BLOCK_DATA(b)) + b->size), 1);
		ft_puts(1," : ");
		print_nb(b->size);
		ft_putl(1, " octets");
		total += b->size;
		b = b->next;
	}
	return (total);
}

void        show_alloc_mem()
{
    long	total;

    if (pthread_mutex_lock(&g_mutex) != 0)
		return ;
	total = 0;
	ft_puts(1, "TINY : ");
	print_hex((long)(get_mem()->tiny), 1);
	ft_putc(1,'\n');
	total += print_block(get_mem()->tiny);
	ft_puts(1, "SMALL : ");
	print_hex((long)(get_mem()->small), 1);
	ft_putc(1,'\n');
	total += print_block(get_mem()->small);
	ft_puts(1, "LARGE : ");
	print_hex((long)(get_mem()->large), 1);
	ft_putc(1,'\n');
    total += print_block(get_mem()->large);
    ft_puts(1, "Total : ");
	print_nb(total);
    ft_putl(1, " octets");
	if (pthread_mutex_unlock(&g_mutex) != 0)
		return ; 
}
