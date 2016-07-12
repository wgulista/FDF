/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:13:22 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:13:23 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			mlx_pixel_put_image(t_env *e, int x, int y, int color)
{
	int			i;

	e->bpp /= 8;
	i = (y * e->sline) + (x * e->bpp);
	e->data[i] = color;
	e->data[i + 1] = color >> 8;
	e->data[i + 2] = color >> 16;
	mlx_pixel_put(e->mlx, e->win, x + e->cam.x, y + e->cam.y, color);
}

void			draw_map(t_env *e)
{
	t_point		pt1;
	t_point		pt2;
	int			i;
	int			j;

	i = -1;
	mlx_clear_window(e->mlx, e->win);
	while (++i < e->nb_line && !(j = 0))
	{
		while (j < e->size[i])
		{
			pt1 = ft_get_point(e, e->points[i][j], &ft_iso);
			if (j < e->size[i] - 1)
			{
				pt2 = ft_get_point(e, e->points[i][j + 1], &ft_iso);
				draw_bresenham(e, pt1, pt2);
			}
			if (i < (e->nb_line - 1) && j < e->size[i + 1])
			{
				pt2 = ft_get_point(e, e->points[i + 1][j], &ft_iso);
				draw_bresenham(e, pt1, pt2);
			}
			j++;
		}
	}
}
