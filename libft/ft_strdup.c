/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:42:07 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/02 18:31:58 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		size;

	size = 0;
	while (str[size] != '\0')
		size++;
	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	size = 0;
	while (str[size] != '\0')
	{
		dest[size] = str[size];
		size++;
	}
	dest[size] = str[size];
	return (dest);
}
