/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:38:35 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/03/22 13:38:36 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


// ebola
void	ft_init(t_main *m)
{
	ft_init_sky(m);
	t_vertex	*vertex;
	t_sector	**sector;

	// углы поворота игрока
	m->player.angle.hor = 0.0;
	m->player.angle.ver = 0.0;
	// вектора поворота игрока
	m->player.vec.x = 1;
	m->player.vec.y = 0;
	m->player.vec.z = 0;
	// позиция игрока
	m->player.pos.x = 1.5;
	m->player.pos.y = 5;
	m->player.pos.z = 5;
	// скоость 
	m->player.movespeed = 0;
	m->player.rotspeed = 0;
	m->player.p_he	= 5;
	m->player.sector = 0;
	// обработкичи кнопок 
	m->eventcall.move_down = 0;
	m->eventcall.move_up = 0;
	m->eventcall.rot_down = 0;
	m->eventcall.rot_left = 0;
	m->eventcall.rot_rigth = 0;
	m->eventcall.rot_up = 0;
	m->eventcall.strafe_left = 0;
	m->eventcall.strafe_rigth = 0;
	m->eventcall.jump_event = 0;
	m->player.ecvator = HEIGHT / 2;

	m->sum_sect = 5;

	// набор точек
	vertex = (t_vertex*)malloc(sizeof(t_vertex) * 8);
	// сектор
	sector = (t_sector**)malloc(sizeof(t_sector*) * 5);
	sector[0] = (t_sector*)malloc(sizeof(t_sector));
	sector[1] = (t_sector*)malloc(sizeof(t_sector));
	sector[2] = (t_sector*)malloc(sizeof(t_sector));
	sector[3] = (t_sector*)malloc(sizeof(t_sector));
	sector[4] = (t_sector*)malloc(sizeof(t_sector));
	// набоh точек сектора
	sector[0]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[0]->heigth.floor = 0;
	sector[0]->heigth.cell = 7;
	sector[0]->typewall[0] = -1;
	sector[0]->typewall[1] = 1;
	sector[0]->typewall[2] = 4;
	sector[0]->typewall[3] = 3;
	sector[0]->color = 0x42f456;

	sector[0]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[0]->vertex[0] = 0;
	sector[0]->vertex[1] = 1;
	sector[0]->vertex[2] = 5;
	sector[0]->vertex[3] = 4;


	sector[1]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[1]->typewall[0] = -1;
	sector[1]->typewall[1] = 2;
	sector[1]->typewall[2] = 4;
	sector[1]->typewall[3] = 0;
	sector[1]->color = 0x41f4b8;

	sector[1]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[1]->vertex[0] = 1;
	sector[1]->vertex[1] = 2;
	sector[1]->vertex[2] = 6;
	sector[1]->vertex[3] = 5;
	sector[1]->heigth.floor = 0;
	sector[1]->heigth.cell = 7;

	sector[2]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[2]->typewall[0] = 1;
	sector[2]->typewall[1] = 4;
	sector[2]->typewall[2] = 3;
	sector[2]->typewall[3] = -1;

	sector[2]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[2]->vertex[0] = 2;
	sector[2]->vertex[1] = 6;
	sector[2]->vertex[2] = 7;
	sector[2]->vertex[3] = 3;
	sector[2]->heigth.floor = 0;
	sector[2]->heigth.cell = 7;
	sector[2]->color = 0x41caf4;

	sector[3]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[3]->typewall[0] = 2;
	sector[3]->typewall[1] = -1;
	sector[3]->typewall[2] = 0;
	sector[3]->typewall[3] = 4;
	sector[3]->color = 0x76ad34;

	sector[3]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[3]->vertex[0] = 7;
	sector[3]->vertex[1] = 3;
	sector[3]->vertex[2] = 0;
	sector[3]->vertex[3] = 4;
	sector[3]->heigth.floor = 0;
	sector[3]->heigth.cell = 7;

	sector[4]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[4]->typewall[0] = 0;
	sector[4]->typewall[1] = 1;
	sector[4]->typewall[2] = 2;
	sector[4]->typewall[3] = 3;
	sector[4]->color = 0xc45417;

	sector[4]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[4]->vertex[0] = 4;
	sector[4]->vertex[1] = 5;
	sector[4]->vertex[2] = 6;
	sector[4]->vertex[3] = 7;
	sector[4]->heigth.floor = 3;
	sector[4]->heigth.cell = 7;





	// кординаты точек
	vertex[0].x = 0;
	vertex[0].y = 0;

	vertex[1].x = 0;
	vertex[1].y = 10;

	vertex[2].x = 10;
	vertex[2].y = 10;

	vertex[3].x = 10;
	vertex[3].y = 0;
	
	vertex[4].x = 3;
	vertex[4].y = 3;

	vertex[5].x = 3;
	vertex[5].y = 7;

	vertex[6].x = 7;
	vertex[6].y = 7;

	vertex[7].x = 7;
	vertex[7].y = 3;

	// кол. точек в секторе
	sector[0]->num_vert = 4;
	sector[1]->num_vert = 4;
	m->vertex = vertex;
	m->sector = sector;
}