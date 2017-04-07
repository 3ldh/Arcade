#include "LibLapin/include/lapin.h"
#include "../include/GfxLapin.hpp"

int	arcade::GfxLapin::test_color(t_color *color)
{
  int	r;
  int	g;
  int	b;

  r = color->full & 0xFF;
  g = (color->full >> 8) & 0xFF;
  b = (color->full >> 16) & 0xFF;

  if (r == 1 && b == 1 && g == 1)
    return (1);
  else
    return (0);
}

void	arcade::GfxLapin::pixel_cpy(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng,
									t_bunny_accurate_position new_pos, u_int32_t colorToPrint)
{
  int		x_font;
  int		y_font;
  t_color	*color;

  y_font = 0;
  while (y_font < fontpng->clipable.clip_height)
    {
      x_font = fontpng->clipable.clip_x_position;
      while (x_font < fontpng->clipable.clip_x_position + 5)
	{
	  color = (t_color *)fontpng->pixels + x_font +
	    fontpng->clipable.clip_width * y_font;
	  if (color->argb[1] != color->argb[2])
	  tekpixel(out, &new_pos, colorToPrint);
	  x_font++;
	  new_pos.x += 1;
	}
      new_pos.x -= 5;
      new_pos.y += 1;
      y_font++;
    }
}
void arcade::GfxLapin::tektext(t_bunny_pixelarray *out, t_bunny_pixelarray *fontpng, t_bunny_accurate_position *pos, const std::string &str,
							   uint32_t color)
{
  int			i;
  t_bunny_accurate_position	new_pos;

  i = 0;
  new_pos.x = pos->x;
  new_pos.y = pos->y;
  while (str[i] != 0)
    {
      fontpng->clipable.clip_x_position = str[i] * 5;
      if (str[i] == 10)
	{
	  new_pos.x = pos->x;
	  new_pos.y += 8;
	}
      else
	{
	  pixel_cpy(out, fontpng, new_pos, color);
	  new_pos.x += 6;
	}
      i++;
    }
}


void	arcade::GfxLapin::tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_accurate_position *pos,
				 unsigned int col)
{
	t_color *color;
	
	if ((pos->x * pos->y) < (pix->clipable.clip_width *
							 pix->clipable.clip_height))
	{
		color =(t_color*)pix->pixels + (int)pos->x + (int)pos->y * pix->clipable.clip_width;
		color->full = col;
	}
}
