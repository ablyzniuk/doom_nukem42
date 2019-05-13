/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 23:08:45 by ablizniu          #+#    #+#             */
/*   Updated: 2019/05/07 23:11:09 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_atof(const char *str)
{
	int			i;
	int			j;
	double		sign;
	double		res;

	i = 0;
	j = 0;
	res = 0;
	while (str[i] == ' ')
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i += ((str[i] == '-' || str[i] == '+') ? 1 : 0);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != '.' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	i += ((str[i] == '.') ? 1 : 0);
	while (str[i + j] && (str[i + j] >= '0' && str[i + j] <= '9'))
		res = res * 10 + (str[i + j++] - '0');
	while (j-- > 0)
		res /= 10;
	return (res * sign);
}