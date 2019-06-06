/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:16:38 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/07 17:44:27 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		main()
{
	t_main	*main;

	main = init_main();
	ft_init(main);
	ft_sdlinit(main);
	ft_sdlloop(main);
	SDL_Quit();
	TTF_Quit();
	//system("leaks doom");
	return (0);
}