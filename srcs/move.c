/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:22 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:24 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		move_pixel_to_left(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->cam.x -= 20.0;
}

void		move_pixel_to_bottom(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->cam.y += 20.0;
}

void		move_pixel_to_right(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->cam.x += 20.0;
}

void		move_pixel_to_top(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->cam.y -= 20.0;
}
