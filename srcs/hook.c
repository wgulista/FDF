/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:13:26 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:13:28 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		quit_program(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_window(e->mlx, e->win);
	free(e);
	exit(2);
}

int			expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, WIDTH_W / 2, HEIGHT_W / 2);
	draw_map(e);
	return (0);
}

int			keyhook(int keycode, t_env *e)
{
	if (keycode == 53)
		quit_program(e);
	if (keycode == 126 || keycode == 13)
		move_pixel_to_top(e);
	if (keycode == 124 || keycode == 2)
		move_pixel_to_right(e);
	if (keycode == 125 || keycode == 1)
		move_pixel_to_bottom(e);
	if (keycode == 123 || keycode == 0)
		move_pixel_to_left(e);
	if (e->scale <= 5.39 && (keycode == 69 || keycode == 24))
		zoom(e);
	if (e->scale > 0.5 && (keycode == 78 || keycode == 27))
		dezoom(e);
	if (keycode == 122)
	{
		mlx_clear_window(e->mlx, e->win);
		if (e->color == 0x00FFFFFF)
			e->color = 2;
		e->color += 2;
	}
	expose_hook(e);
	return (0);
}
