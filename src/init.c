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
	m->player.pos.x = 5;
	m->player.pos.y = 5;
	m->player.pos.z = 5;
	// скоость 
	m->player.movespeed = 0;
	m->player.rotspeed = 0;
	m->player.p_he	= 6;
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

	m->sum_sect = 2;

	// набор точек
	vertex = (t_vertex*)malloc(sizeof(t_vertex) * 8);
	// сектор
	sector = (t_sector**)malloc(sizeof(t_sector*) * 2);
	sector[0] = (t_sector*)malloc(sizeof(t_sector));
	sector[1] = (t_sector*)malloc(sizeof(t_sector));
	// набор точек сектора
	sector[0]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[0]->heigth.z = 2000;
	sector[0]->typewall[0] = -1;
	sector[0]->typewall[1] = 1;
	sector[0]->typewall[2] = -1;
	sector[0]->typewall[3] = -1;

	sector[0]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[0]->vertex[0] = 0;
	sector[0]->vertex[1] = 1;
	sector[0]->vertex[2] = 2;
	sector[0]->vertex[3] = 3;
	sector[0]->heigth.max_he = 20;
	sector[0]->heigth.min_he = 0;
//	sector[0]->heigth.z = (sector[0]->heigth.max_he - sector[0]->heigth.min_he) / 2;


	sector[1]->typewall = (int*)malloc(sizeof(int) * 4);
	sector[1]->typewall[0] = -1;
	sector[1]->typewall[1] = -1;
	sector[1]->typewall[2] = -1;
	sector[1]->typewall[3] = 0;

	sector[1]->vertex = (int*)malloc(sizeof(int) * 5);
	sector[1]->heigth.z = 1500;
	sector[1]->vertex[0] = 4;
	sector[1]->vertex[1] = 5;
	sector[1]->vertex[2] = 6;
	sector[1]->vertex[3] = 7;
	sector[1]->heigth.max_he = 20;
	sector[1]->heigth.min_he = 0;
//	sector[1]->heigth.z = (sector[1]->heigth.max_he - sector[1]->heigth.min_he) / 2;
	// кординаты точек
	vertex[0].x = 0;
	vertex[0].y = 0;

	vertex[1].x = 0;
	vertex[1].y = 10;

	vertex[2].x = 10;
	vertex[2].y = 10;

	vertex[3].x = 10;
	vertex[3].y = 0;
	
	vertex[4].x = 0;
	vertex[4].y = 10;

	vertex[5].x = 0;
	vertex[5].y = 20;

	vertex[6].x = 10;
	vertex[6].y = 20;

	vertex[7].x = 10;
	vertex[7].y = 10;

	// кол. точек в секторе
	sector[0]->num_vert = 4;
	sector[1]->num_vert = 4;
	m->vertex = vertex;
	m->sector = sector;
}