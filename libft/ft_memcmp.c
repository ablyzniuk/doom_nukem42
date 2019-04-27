/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:40:53 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/04 10:04:14 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char*)memptr1;
	s2 = (const unsigned char*)memptr2;
	while (num--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (num)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
