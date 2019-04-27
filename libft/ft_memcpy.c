/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:44:17 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/04 10:00:11 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	dest = (unsigned char*)destptr;
	src = (unsigned char*)srcptr;
	while (i < (unsigned int)num && num > 0)
	{
		dest[i] = src[i];
		i++;
	}
	return (destptr);
}
