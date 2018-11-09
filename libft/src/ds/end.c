/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <cmalfroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ds.h"

inline void	*ft_deqend(t_deq *self)
{
	return ((char *)self->buf + (self->len * self->isz));
}

inline char	*ft_sdsend(t_sds *self)
{
	return (self->buf + self->len);
}

inline void	*ft_vecend(t_vec *self)
{
	return ((char *)self->buf + (self->len * self->isz));
}
