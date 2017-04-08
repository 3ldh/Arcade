/*
** my_blit.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:20:08 2016 Mathieu Sauvau
** Last update Wed Feb 24 15:54:04 2016 Mathieu Sauvau
*/

#include <LibLapin/include/lapin.h>
#include <include/GfxLapin.hpp>

t_color arcade::GfxLapin::blend(t_color bg, t_color fg) {
	t_color result;
	unsigned int alpha;
	unsigned int inv_alpha;
	
	alpha = fg.argb[ALPHA_CMP] + 1;
	inv_alpha = 256 - fg.argb[ALPHA_CMP];
	result.argb[RED_CMP] = ((alpha * fg.argb[RED_CMP] + inv_alpha * bg.argb[RED_CMP]) >> 8);
	result.argb[GREEN_CMP] = ((alpha * fg.argb[GREEN_CMP] + inv_alpha * bg.argb[GREEN_CMP]) >> 8);
	result.argb[BLUE_CMP] = ((alpha * fg.argb[BLUE_CMP] + inv_alpha * bg.argb[BLUE_CMP]) >> 8);
	result.argb[ALPHA_CMP] = 0xff;
	return (result);
}

void arcade::GfxLapin::my_blit(t_bunny_pixelarray *pix_ar,
							   t_bunny_pixelarray *pix_ar2,
							   t_bunny_position offset) {
	int i;
	int n;
	t_bunny_position pos;
	t_bunny_position pos2;
	t_color *bg;
	t_color *fg;
	
	pos.x = offset.x - 1;
	pos2.x = -1;
	bg = (t_color *) pix_ar->pixels;
	fg = (t_color *) pix_ar2->pixels;
	while (++pos.x < pix_ar2->clipable.clip_width + offset.x) {
		pos.y = offset.y - 1;
		pos2.y = -1;
		++pos2.x;
		while (++pos.y < pix_ar2->clipable.clip_height + offset.y) {
			++pos2.y;
			i = pix_ar->clipable.clip_width * pos.y + pos.x;
			n = pix_ar2->clipable.clip_width * pos2.y + pos2.x;
			if (fg[n].argb[ALPHA_CMP] != 0)
				bg[i] = blend(bg[i], fg[n]);
		}
	}
}
