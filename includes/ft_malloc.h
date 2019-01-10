/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:22:05 by cmalfroy          #+#    #+#             */
/*   Updated: 2019/01/10 15:43:52 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>
# include "../libft/libft.h"

# define TINY			256
# define SMALL			4096

# define PAGE_SIZE		(getpagesize())
# define TINY_MIN		(PAGE_SIZE * 100 * TINY)
# define SMALL_MIN		(PAGE_SIZE * 100 * SMALL)
# define BLOCK_SIZE		sizeof(struct s_block)
# define BLOCK_DATA(b)	(((void*)b + BLOCK_SIZE))
# define ALLIGN4(x)		(((((x) - 1) >> 2) << 2) + 4)

typedef struct		s_block
{
	size_t			size;
	size_t			is_free;
	struct s_block	*next;
}					t_block;

typedef struct		s_mem
{
	struct s_block	*tiny;
	struct s_block	*small;
	struct s_block	*large;
}					t_mem;

/*
 ** Basic functions
*/

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*calloc(size_t count, size_t size);
void				show_alloc_mem(void);

/*
 ** Helpers for show_alloc_mem
*/

void				show_alloc_mem_ex(void);
void				print_hex(long nb, char first);
void				print_nb(long nb);

/*
 ** utils.c
*/

t_mem				*get_mem(void);
t_block				*find_ptr(t_block *b, void *ptr);
void				split_block(t_block *b, size_t size);
void				merge_block(t_block *b);

pthread_mutex_t		*get_lock();

#endif
