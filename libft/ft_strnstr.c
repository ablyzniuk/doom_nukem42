/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:49:52 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 18:35:28 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s2);
	if (!len)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[j] == s1[i + j] && i + j < n)
		{
			if (j == len - 1)
				return ((char *)&s1[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
