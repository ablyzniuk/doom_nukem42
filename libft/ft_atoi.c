/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:52:40 by yalytvyn          #+#    #+#             */
/*   Updated: 2018/11/05 12:07:44 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					flag;
	unsigned long int	num;

	num = 0;
	flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		if ((num > 922337203685477580 || (num == 922337203685477580
			&& (*str - '0') > 7)) && flag == 1)
			return (-1);
		else if ((num > 922337203685477580 || (num == 922337203685477580
			&& (*str - '0') > 8)) && flag == -1)
			return (0);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return ((int)(num * flag));
}
