/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:19:13 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/05/08 21:50:37 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

double	ft_dist(t_vertex start, t_vertex end)
{
	double	dist;

	dist = sqrt(pow(end.x - start.x, 2.0) + pow(end.y - start.y, 2.0));
	return (dist);
}

double	ft_dist_cord(double x1, double y1, double x2, double y2)
{
	double	dist;

	dist = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
	return (dist);
}

double	ft_get_dist_cols(t_main *m, t_cols_wall *lst, t_collision cols, t_vertex pos_vec)
{
	double		a;
	double		b;
	double		c;
	double		dist;
	double		t;

	cols.wall_len = ft_dist(lst->start, lst->end);
	cols.len_start = ft_dist(lst->start, pos_vec);
	cols.len_end = ft_dist(lst->end, pos_vec);
	if (cols.len_start > ft_dist_cord(cols.len_end, cols.wall_len, 0, 0)
	|| cols.len_end > ft_dist_cord(cols.len_start, cols.wall_len, 0, 0))
		return (-1);
	a = lst->end.y - lst->start.y;
	b = lst->start.x - lst->end.x;
	c = -lst->start.x * (lst->end.y - lst->start.y)
	+ lst->start.y * (lst->end.x - lst->start.x);
	if (c > 0)
	{
		a = -a;
		b = -b;
		c = -c;
	}
	t = ft_dist_cord(a, b, 0, 0);
	dist = (a * pos_vec.x + b * pos_vec.y + c) / t;
	return (dist);
}

int32_t ft_collision(t_main *m, t_vertex pos_vec, double move)
{
	t_collision	cols;
	t_cols_wall	*lst;
	t_vertex	pos_x;
	t_vertex	pos_y;
	t_vertex	res;
	double		dist;

	cols.flag_x = 0;
	cols.flag_y = 0;
	cols.flag_tp_x = -1;
	cols.flag_tp_y = -1;
	lst = m->sector[m->player.sector].cols;
	while (lst)
	{
		if (cols.flag_x == 0)
		{
			pos_x.x = m->player.pos.x + pos_vec.x * move;
			pos_x.y = m->player.pos.y;
			dist = fabs(ft_get_dist_cols(m, lst, cols, pos_x));
			res = ft_intersection(m->player.pos, pos_x, lst->start, lst->end);
				printf("%f\n", ft_dist_cord(m->player.pos.x, pos_x.x, m->player.pos.y, pos_x.y));
			if (dist <= 0.7 && lst->type == -1)
			{
					cols.flag_x = 1;
			}
			else if (lst->type != -1 && lst->sector == m->player.sector)
			{
				if (res.z != -1)
				{
						printf("Dec\n");
						printf("%f\n", ft_dist_cord(m->player.pos.x, pos_x.x, m->player.pos.y, pos_x.y));
					cols.flag_tp_x = lst->type;
				}
			}
		}
		if (cols.flag_y == 0)
		{
			pos_y.x = m->player.pos.x;
			pos_y.y = m->player.pos.y + pos_vec.y * move;
			dist = fabs(ft_get_dist_cols(m, lst, cols, pos_y));
			res = ft_intersection(m->player.pos, pos_y, lst->start, lst->end);
			if (dist <= 0.7 && lst->type == -1)
			{
			
				cols.flag_y = 1;
			}
			else if (lst->type != -1 && lst->sector == m->player.sector)
			{	
				if (res.z != -1)
				{
				printf("Dec\n");
					cols.flag_tp_y = lst->type;
				}
			}
		}
		lst = lst->next;
	}

	if (cols.flag_tp_x != -1 || cols.flag_tp_y != -1)
	{
		printf ("x %d y %d\n",cols.flag_tp_x, cols.flag_tp_y );
		if (cols.flag_tp_x != -1)
			m->player.sector = cols.flag_tp_x;
		else if (cols.flag_tp_y != -1)
			m->player.sector = cols.flag_tp_y;
	}
	if (cols.flag_x != 1)
	{
		m->player.pos.x += pos_vec.x * move;
	}
	if (cols.flag_y != 1)
	{
		m->player.pos.y += pos_vec.y * move;
	}
//	SDL_Log("---\n");
	return (1);

}

// var x,y:array [0..2] of real;
//  r0,r1,r2,r12,a,b,c,t:real;
//  i:integer;
 
// function dist (x1,y1,x2,y2:real):real; {Расстояние между точками}
// begin
//  dist:=sqrt(sqr(x2-x1)+sqr(y2-y1));
// end;
 
// begin
//  {Ввод данных}
//  writeln;
//  for i:=0 to 2 do begin
//   repeat
//    write ('Введите R',i,' (координаты X и Y):');
//    {$I-}readln (x[i],y[i]);{$I+}
//   until IoResult=0;
//  end;
//  {Реализация алгоритма и вывод результатов}
//  r1:=dist(x[0],y[0],x[1],y[1]);
//  r2:=dist(x[0],y[0],x[2],y[2]);
//  r12:=dist(x[1],y[1],x[2],y[2]);
//  if r1>=dist(r2,r12,0,0) then
//   writeln ('Точка правее (x2,y2),r=',r2:6:2)
//  else if r2>=dist(r1,r12,0,0) then
//   writeln ('Точка левее (x1,y1),r=',r1:6:2)
//  else begin
//   a:=y[2]-y[1]; b:=x[1]-x[2]; c:=-x[1]*(y[2]-y[1])+y[1]*(x[2]-x[1]);
//   t:=dist (a,b,0,0);
//   if c>0 then begin a:=-a; b:=-b; c:=-c; end;
//   r0:=(a*x[0]+b*y[0]+c)/t;
//   write ('Расстояние от точки до отрезка=',r0:6:2);
//   if r0<0 then write (' (точка под отрезком)');
//  end;
//  reset (input); readln;
// end.



	// size_t		wall_sect;
	// size_t		k;
	// int32_t		flag;
	// int32_t		he;
	// t_vertex	res;
	// t_vertex	end;
	// t_vertex	start;
	// t_vertex	wall_start;
	// t_vertex	wall_end;

	// k = 0; 
	// wall_sect = 0;
	// flag = 0;
	// start.x = m->player.pos.x;
	// start.y = m->player.pos.y;
	// while (wall_sect < m->sector[m->player.sector].vertex_arr_len)
	// {
	// 	if (wall_sect == 0)
	// 		k = m->sector[m->player.sector].vertex_arr_len - 1;
	// 	else
	// 		k = wall_sect - 1;
	// 	wall_start.x = m->sector[m->player.sector].vertex[k][1];
	// 	wall_start.y = m->sector[m->player.sector].vertex[k][0];
	// 	wall_end.x = m->sector[m->player.sector].vertex[wall_sect][1];
	// 	wall_end.y = m->sector[m->player.sector].vertex[wall_sect][0];
	// 	if (m->sector[m->player.sector].transit[wall_sect] == -1)
	// 	{
	// 		end.x = m->player.pos.x + pos_vec.x * 15 * move;
	// 		end.y = m->player.pos.y + pos_vec.y * 15 * move;
	// 	}
	// 	else
	// 	{
	// 		end.x = m->player.pos.x + pos_vec.x * move;
	// 		end.y = m->player.pos.y + pos_vec.y * move;
	// 	}
	// 	res = ft_intersection(start, end, wall_start, wall_end);
	// 	if (m->sector[m->player.sector].transit[wall_sect] != -1 && res.z != -1)
	// 	{
	// 		he = m->sector[m->sector[m->player.sector].transit[wall_sect]].heigth.floor;
	// 		if (m->player.pos.z + 2 >= he)
	// 			flag = 1;
	// 		break;
	// 	}
	// 	else if (res.z != -1 && m->sector[m->player.sector].transit[wall_sect] == -1)
	// 		return (-1);
	// 	wall_sect++;
	// }
	// if (res.z == -1)
	// 	return (1);
	// if (flag == 1)
	// {
	// 	m->player.sector = m->sector[m->player.sector].transit[wall_sect];
	// 	return (1);
	// }