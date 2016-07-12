/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:15:26 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:15:27 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				get_color(double z)
{
	int			color;

	if (z > 10)
		color = 0x00FFFFFF;
	if (z >= 0.1 && z < 5.4)
		color = 0x0000FF00;
	if (z >= 5.4 && z < 9.9)
		color = 0x00F4A460;
	if (z <= -0.0)
		color = 0x000000FF;
	return (color);
}

void			more_h_than_v(t_env *e, t_point p1, t_point d, t_point s)
{
	int			i;
	float		inc;

	i = 0;
	inc = d.x / 2;
	p1.color = get_color(p1.z);
	mlx_pixel_put_image(e, p1.x, p1.y, e->color);
	while (i < d.x)
	{
		inc += d.y;
		if (inc >= d.x)
		{
			inc -= d.x;
			p1.y += s.y;
		}
		p1.x += s.x;
		mlx_pixel_put_image(e, p1.x, p1.y, e->color);
		i++;
	}
}

void			more_v_than_h(t_env *e, t_point p1, t_point d, t_point s)
{
	int			i;
	float		inc;

	i = 0;
	inc = d.x / 2;
	while (i < d.y)
	{
		inc += d.x;
		if (inc >= d.y)
		{
			inc -= d.y;
			p1.x += s.x;
		}
		p1.y += s.y;
		mlx_pixel_put_image(e, p1.x, p1.y, e->color);
		i++;
	}
}

void			draw_bresenham(t_env *e, t_point p1, t_point p2)
{
	t_point		d;
	t_point		s;

	d.x = (p2.x - p1.x);
	d.y = (p2.y - p1.y);
	s.x = (d.x > 0) ? 1 : -1;
	s.y = (d.y > 0) ? 1 : -1;
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	mlx_pixel_put_image(e, p1.x, p1.y, e->color);
	if (d.x >= d.y)
		more_h_than_v(e, p1, d, s);
	else
		more_v_than_h(e, p1, d, s);
}
