/*
** tektext.c for tektext in /home/peau_c/rendu/Lib/chatty_2020
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Feb 18 16:11:24 2016 Clement Peau
** Last update Wed Feb 24 19:51:46 2016 Clement Peau
*/

#include "LibLapin/include/lapin.h"
#include "../include/GfxLapin.hpp"

void arcade::GfxLapin::tekpixel(t_bunny_pixelarray &pix,
								t_bunny_position pos,
								unsigned int col) {
	t_color *color;
	
	if ((pos.x * pos.y) < (pix.clipable.clip_width *
						   pix.clipable.clip_height)) {
		color = (t_color *) pix.pixels + (int) pos.x + (int) pos.y * pix.clipable.clip_width;
		color->full = col;
	}
}
void arcade::GfxLapin::pixel_cpy(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng, t_bunny_position new_pos,
								 u_int32_t i) {
	int x_font;
	int y_font;
	t_color *color;
	
	y_font = 0;
	while (y_font < fontpng->clipable.clip_height) {
		x_font = fontpng->clipable.clip_x_position;
		while (x_font < fontpng->clipable.clip_x_position + 5) {
			color = (t_color *) fontpng->pixels + x_font +
					fontpng->clipable.clip_width * y_font;
			if (color->argb[1] != color->argb[2])
				tekpixel(*out, new_pos, i);
			x_font++;
			new_pos.x += 1;
		}
		new_pos.x -= 5;
		new_pos.y += 1;
		y_font++;
	}
}

void arcade::GfxLapin::tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng,
							   const t_bunny_position *pos, const char *str, u_int32_t color) {
	if (!fontpng)
		return;
	int i;
	t_bunny_position new_pos;
	
	i = 0;
	new_pos.x = pos->x;
	new_pos.y = pos->y;
	while (str[i] != 0) {
		fontpng->clipable.clip_x_position = str[i] * 5;
		if (str[i] == 10) {
			new_pos.x = pos->x;
			new_pos.y += 8;
		} else {
			pixel_cpy(out, fontpng, new_pos, color);
			new_pos.x += 6;
		}
		i++;
	}
}
