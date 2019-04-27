/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:53:57 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 16:56:40 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char*)destptr;
	src = (unsigned char*)srcptr;
	i = 0;
	if (src < dest)
	{
		while (num--)
			dest[num] = src[num];
	}
	else
	{
		while (i < (unsigned int)num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
