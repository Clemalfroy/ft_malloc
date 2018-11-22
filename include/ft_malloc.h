/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <libft.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/mman.h>
# include <fcntl.h>

# define TINY 128
# define SMALL 1024
# define PAGE_SIZE getpagesize()
# define TINY_MIN ((((TINY * 100) / (PAGE_SIZE)) + 1) * PAGE_SIZE)
# define SMALL_MIN ((((SMALL * 100) / (PAGE_SIZE)) + 1) * PAGE_SIZE)
# define BLOCK_SIZE sizeof(struct s_block)
# define BLOCK_DATA(b) (((void*)(b) + BLOCK_SIZE))
# define IS_TINY(x) (((x)) <= (TINY))
# define IS_SMALL(x) (((x)) > (TINY) && (x) <= (SMALL))
# define IS_LARGE(x) (((x)) > (SMALL))
# define ALIGNMENT 16
# define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))

enum			e_opt
{
	OPT_TINY = 1 << 1,
	OPT_SMALL = 1 << 2,
	OPT_LARGE = 1 << 3,
};

typedef struct s_block t_block;

typedef struct		s_block {
  size_t			size;
  char   			allocated;
  t_block			*next;
  t_block			*prev;
}					t_block;

typedef struct		s_data {
	t_block			*tiny;
	t_block			*small;
	t_block			*large;
}					t_data;

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
static t_data 			*g_mem = NULL;

void 		*malloc(size_t size);
void 		*realloc(void *ptr, size_t size);
void 		free(void *ptr);
void		show_alloc_mem();
void        *calloc(size_t elements, size_t size);
t_data		*get_mem();
#endif
