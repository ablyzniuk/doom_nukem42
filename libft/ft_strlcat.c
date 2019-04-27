/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:19:56 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 19:13:43 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destptr, const char *srcptr, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (size == 0)
		return (ft_strlen(srcptr));
	while (destptr[i] && i < size)
		i++;
	len = i;
	while (srcptr[i - len] && i < size - 1)
	{
		destptr[i] = srcptr[i - len];
		i++;
	}
	if (len < size)
		destptr[i] = '\0';
	return (len + ft_strlen(srcptr));
}
