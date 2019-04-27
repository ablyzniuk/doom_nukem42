/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:04:37 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 18:32:28 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (destptr[i] != '\0')
		i++;
	while (srcptr[k] != '\0')
	{
		destptr[i] = srcptr[k];
		i++;
		k++;
	}
	destptr[i] = '\0';
	return (destptr);
}
