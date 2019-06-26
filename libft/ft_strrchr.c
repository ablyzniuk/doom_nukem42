/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:31:09 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/10/31 12:50:48 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int val)
{
	int		flag;
	int		i;
	char	*ptr;

	i = 0;
	flag = -1;
	ptr = (char*)str;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == val)
			flag = i;
		i++;
	}
	if (ptr[i] == val)
		flag = i;
	if (flag != -1)
	{
		ptr = &ptr[flag];
		return (ptr);
	}
	return (NULL);
}
