/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:38:33 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/03 13:42:59 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(int n)
{
	int	size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_lenstr(n);
	neg = 0;
	if (n < 0)
	{
		n = -n;
		size++;
		neg = 1;
	}
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	str[--size] = n % 10 + 48;
	while (n /= 10)
		str[--size] = n % 10 + 48;
	if (neg)
		str[0] = '-';
	return (str);
}
