/*
** text_gui.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:12:54 2016 Mathieu Sauvau
** Last update Tue Feb 23 11:48:21 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/GfxLapin.hpp"
#include "LibLapin/include/lapin.h"

t_bunny_position arcade::GfxLapin::offset_center_txt(char *str) {
	t_bunny_position offset;
	
	offset.x = -(((int) strlen(str) - 1) * 4);
	offset.y = -4;
	return (offset);
}

void arcade::GfxLapin::write_png(t_bunny_pixelarray *pix_ar,
								 t_bunny_pixelarray *font,
								 char *str) {
	t_bunny_pixelarray *letter;
	int offset;
	
	offset = 0;
	if (!str)
		return;
	while (*str) {
		if ((letter = get_letter(font, *str++)) == NULL) {
			write(1, "can't find letter\n", 18);
			break;
		}
		my_blit(pix_ar, letter, pos_(offset, 0));
		offset += 8;
		bunny_delete_clipable(&letter->clipable);
	}
}

void arcade::GfxLapin::my_fill(t_bunny_pixelarray *pix, uint32_t color) {
	t_color *tmp;
	
	for(int i = 0; i < pix->clipable.clip_width * pix->clipable.clip_height; i++) {
		tmp = (t_color *) pix->pixels + i;
		tmp->full = color;
	}
}

t_bunny_pixelarray *arcade::GfxLapin::get_letter(t_bunny_pixelarray *f, int index) {
	t_bunny_pixelarray *l;
	t_color *f_color;
	t_color *l_color;
	int start;
	int x;
	int x2;
	int y;
	
	if ((l = bunny_new_pixelarray(5, 7)) == NULL)
		return (NULL);
	f_color = (t_color *) f->pixels;
	l_color = (t_color *) l->pixels;
	start = 5 * index;
	x = start - 1;
	x2 = -1;
	my_fill(l, 0x00000000);
	while (++x < start + 5 && ++x2 != -2) {
		y = -1;
		while (++y < 7)
			l_color[5 * y + x2].full = f_color[f->clipable.clip_width * y + x].full;
	}
	return (l);
}
