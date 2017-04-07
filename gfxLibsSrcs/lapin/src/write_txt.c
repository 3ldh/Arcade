/*
** write_txt.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Feb 18 17:23:21 2016 Mathieu Sauvau
** Last update Wed Feb 24 19:00:14 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <unistd.h>
#include "libgui.h"

void			write_txt_next(t_bunny_position *offset,
				       t_bunny_pixelarray *pix_ar,
				       t_bunny_pixelarray *letter)
{
  if (offset->x > pix_ar->clipable.clip_width - 5)
    *offset = pos_(0, offset->y + 9);
  my_blit(pix_ar, letter, *offset);
  offset->x += 8;
  bunny_delete_clipable(&letter->clipable);
}

void			write_txt(t_bunny_pixelarray *pix_ar,
				  t_bunny_pixelarray *font,
				  char *str)
{
  t_bunny_pixelarray	*letter;
  t_bunny_position	offset;

  if (!str)
    return ;
  offset = pos_(0, 0);
  while (*str)
    {
      if (*str != '\n')
	{
	  if ((letter = get_letter(font, *str++)) == NULL)
	    {
	      write(1, "can't find letter\n", 18);
	      break;
	    }
	  write_txt_next(&offset, pix_ar, letter);
	}
      else
	{
	  (void)*str++;
	  offset = pos_(0, offset.y + 9);
	}
    }
}
