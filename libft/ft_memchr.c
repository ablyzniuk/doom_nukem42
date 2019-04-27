/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:08:27 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 17:06:12 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	unsigned char	*str;
	unsigned int	i;
	void			*ptr;

	str = (unsigned char*)memptr;
	i = 0;
	while (i < (unsigned int)num && num > 0)
	{
		if (str[i] == (unsigned char)val)
		{
			ptr = &str[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
