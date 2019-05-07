/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:16:38 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 13:16:39 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		main()
{
	t_main	*m;

	m = (t_main*)malloc(sizeof(t_main));
	ft_sdlinit(m);
	ft_init(m);
	ft_sdlloop(m);


//	system("leaks doom");
	return (0);
}