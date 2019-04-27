/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:01:37 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/04 13:26:04 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char val)
{
	size_t	count;
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != val && (s[i + 1] == val || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}
