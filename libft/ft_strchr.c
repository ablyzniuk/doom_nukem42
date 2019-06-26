/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:09:48 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 18:34:09 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int val)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char*)str;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == val)
		{
			ptr = &ptr[i];
			return (ptr);
		}
		i++;
	}
	if (ptr[i] == val)
	{
		ptr = &ptr[i];
		return (ptr);
	}
	return (NULL);
}
