/*
** my_blit.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/libgui
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:20:08 2016 Mathieu Sauvau
** Last update Wed Feb 24 15:54:04 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include <unistd.h>
#include "libgui.h"

t_color			blend(t_color bg, t_color fg)
{
  t_color		result;
  unsigned int		alpha;
  unsigned int		inv_alpha;

  alpha = fg.ALPHA_ + 1;
  inv_alpha = 256 - fg.ALPHA_;
  result.RED_ = ((alpha * fg.RED_ + inv_alpha * bg.RED_) >> 8);
  result.GREEN_ = ((alpha * fg.GREEN_ + inv_alpha * bg.GREEN_) >> 8);
  result.BLUE_ = ((alpha * fg.BLUE_ + inv_alpha * bg.BLUE_) >> 8);
  result.ALPHA_ = 0xff;
  return (result);
}

void			my_blit(t_bunny_pixelarray *pix_ar,
				t_bunny_pixelarray *pix_ar2,
				t_bunny_position offset)
{
  int			i;
  int			n;
  t_bunny_position	pos;
  t_bunny_position	pos2;
  t_color		*bg;
  t_color		*fg;

  pos.x = offset.x - 1;
  pos2.x = -1;
  bg = pix_ar->pixels;
  fg = pix_ar2->pixels;
  while (++pos.x < pix_ar2->clipable.clip_width + offset.x)
    {
      pos.y = offset.y - 1;
      pos2.y = -1;
      ++pos2.x;
      while (++pos.y < pix_ar2->clipable.clip_height + offset.y)
	{
	  ++pos2.y;
	  i = pix_ar->clipable.clip_width * pos.y + pos.x;
	  n = pix_ar2->clipable.clip_width * pos2.y + pos2.x;
	  if (fg[n].ALPHA_ != 0)
	    bg[i] = blend(bg[i], fg[n]);
	}
    }
}
