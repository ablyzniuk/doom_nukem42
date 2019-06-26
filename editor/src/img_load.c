/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:09:15 by vrudyka           #+#    #+#             */
/*   Updated: 2019/06/22 10:42:32 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void				load_img_pass(t_edit *edit)
{
	int				i;

	i = -1;
	edit->bmp[0] = SDL_LoadBMP("../resources/ed/icons/p/vector.bmp");
	edit->bmp[1] = SDL_LoadBMP("../resources/ed/icons/p/obj.bmp");
	edit->bmp[2] = SDL_LoadBMP("../resources/ed/icons/p/bind.bmp");
	edit->bmp[3] = SDL_LoadBMP("../resources/ed/icons/p/declare.bmp");
	edit->bmp[4] = SDL_LoadBMP("../resources/ed/icons/p/player.bmp");
	edit->bmp[5] = SDL_LoadBMP("../resources/ed/icons/p/enemy.bmp");
	edit->bmp[6] = SDL_LoadBMP("../resources/ed/icons/p/edit.bmp");
	edit->bmp[7] = SDL_LoadBMP("../resources/ed/icons/p/text.bmp");
	edit->bmp[8] = SDL_LoadBMP("../resources/ed/icons/p/ceil.bmp");
	edit->bmp[9] = SDL_LoadBMP("../resources/ed/icons/p/floor.bmp");
	edit->bmp[10] = SDL_LoadBMP("../resources/ed/tex/brick.bmp");
	edit->bmp[11] = SDL_LoadBMP("../resources/ed/tex/grass.bmp");
	edit->bmp[12] = SDL_LoadBMP("../resources/ed/tex/milano.bmp");
	edit->bmp[13] = SDL_LoadBMP("../resources/ed/tex/rock.bmp");
	edit->bmp[14] = SDL_LoadBMP("../resources/ed/tex/tile.bmp");
	edit->bmp[15] = SDL_LoadBMP("../resources/ed/tex/win.bmp");
	while (++i < NUM_TEX_P)
		if (edit->bmp[i] == NULL)
			terminate("Missing texture passive", NULL);
}

void				load_img_active(t_edit *edit)
{
	int				i;

	i = -1;
	edit->bmp_a[0] = SDL_LoadBMP("../resources/ed/icons/a/vector_closed.bmp");
	edit->bmp_a[1] = SDL_LoadBMP("../resources/ed/icons/a/obj.bmp");
	edit->bmp_a[2] = SDL_LoadBMP("../resources/ed/icons/a/bind.bmp");
	edit->bmp_a[3] = SDL_LoadBMP("../resources/ed/icons/a/declare.bmp");
	edit->bmp_a[4] = SDL_LoadBMP("../resources/ed/icons/a/player.bmp");
	edit->bmp_a[5] = SDL_LoadBMP("../resources/ed/icons/a/enemy.bmp");
	edit->bmp_a[6] = SDL_LoadBMP("../resources/ed/icons/a/edit.bmp");
	edit->bmp_a[7] = SDL_LoadBMP("../resources/ed/icons/a/text.bmp");
	edit->bmp_a[8] = SDL_LoadBMP("../resources/ed/icons/a/ceil.bmp");
	edit->bmp_a[9] = SDL_LoadBMP("../resources/ed/icons/a/floor.bmp");
	edit->bmp_a[10] = SDL_LoadBMP("../resources/ed/icons/a/vector_not.bmp");
	while (++i < NUM_TEX_A)
		if (edit->bmp_a[i] == NULL)
			terminate("Missing texture", NULL);
	if ((edit->icon = SDL_LoadBMP("../resources/ed/icon.bmp")) == NULL)
		terminate("Missing texture active", NULL);
}

void				load_img_obj(t_edit *edit)
{
	int				i;

	i = -1;
	edit->obj[0] = SDL_LoadBMP("../resources/ed/obj/obj.bmp");
	edit->obj[1] = SDL_LoadBMP("../resources/ed/obj/bad.bmp");
	edit->obj[2] = SDL_LoadBMP("../resources/ed/obj/good.bmp");
	while (++i < NUM_TEX_O)
		if (edit->obj[i] == NULL)
			terminate("Missing texture object", NULL);
}

void				load_text(t_edit *edit)
{
	int				i;

	i = -1;
	edit->text[0] = SDL_LoadBMP("../resources/ed/text/choose.bmp");
	edit->text[1] = SDL_LoadBMP("../resources/ed/text/type.bmp");
	while (++i < 2)
		if (edit->text[i] == NULL)
			terminate("Missing instruction text", NULL);
}
