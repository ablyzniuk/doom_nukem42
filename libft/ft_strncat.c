/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:10:00 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 18:32:58 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (destptr[i] != '\0')
		i++;
	while (srcptr[k] != '\0' && k < num && srcptr != NULL)
	{
		destptr[i] = srcptr[k];
		k++;
		i++;
	}
	destptr[i] = '\0';
	return (destptr);
}
