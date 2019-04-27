/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:05:25 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/05 16:54:03 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wordcount(char const *s, char val)
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

static size_t	ft_s_len(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static char		**ft_content(char	const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			str[k][j] = s[i];
			j++;
			i++;
		}
		str[k][j] = '\0';
		k++;
	}
	return (str);
}

char			**ft_strsplit(char	const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s || !(str = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!(str[j] = (char*)malloc(sizeof(char) * (ft_s_len(s, c, i) + 1))))
		{
			ft_memdel((void*)str);
			return (NULL);
		}
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	str = ft_content(s, c, str);
	str[ft_wordcount(s, c)] = NULL;
	return (str);
}
