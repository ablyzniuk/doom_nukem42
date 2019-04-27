/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:52:41 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/10/31 13:49:34 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		buf;

	i = 0;
	buf = 0;
	buf = ft_strlen(s2);
	if (buf == 0)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j == buf - 1)
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
