/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:09:32 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/03 13:41:43 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_length(const char *s)
{
	size_t	len;
	size_t	buf;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	buf = len;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		buf--;
		i++;
	}
	len--;
	while (len > 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			&& s[i] != '\0')
	{
		buf--;
		len--;
	}
	if (buf == 0)
		return (0);
	return (buf);
}

char				*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	size = ft_length(s);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (size > 0)
	{
		str[j] = s[i];
		i++;
		j++;
		size--;
	}
	str[j] = '\0';
	return (str);
}
