/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:39:30 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 18:55:16 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destptr, const void *srcptr, int ch, size_t count)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned int	i;

	i = 0;
	dest = (unsigned char*)destptr;
	src = (unsigned char*)srcptr;
	while (i < (unsigned int)count)
	{
		dest[i] = src[i];
		if (dest[i] == (unsigned char)ch)
		{
			destptr = &dest[i + 1];
			return (destptr);
		}
		i++;
	}
	return (NULL);
}
