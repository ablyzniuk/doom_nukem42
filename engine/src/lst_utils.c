/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:06:42 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/06/23 15:18:09 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_cols_wall		*ft_cr_new_list(void)
{
	t_cols_wall	*lst;

	if (!(lst = (t_cols_wall *)ft_memalloc(sizeof(t_cols_wall))))
		print_error(BAD_ALLOC);
	return (lst);
}

void			ft_lst_add_back(t_cols_wall *start, t_cols_wall *lst)
{
	t_cols_wall	*last;

	last = start;
	while (last->next)
		last = last->next;
	last->next = lst;
}
