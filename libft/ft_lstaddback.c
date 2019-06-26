/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:00:05 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/05 11:39:15 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **list, void const *content, size_t content_size)
{
	t_list	*new_list;
	t_list	*tmp;
	t_list	*head;

	if (list == NULL)
		return ;
	tmp = *list;
	head = tmp;
	new_list = ft_lstnew(content, content_size);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_list;
	*list = head;
}
