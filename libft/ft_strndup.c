/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:33:00 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/26 13:33:31 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strndup(const char *src, size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
