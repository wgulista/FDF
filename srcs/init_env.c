/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:13:31 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:13:33 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env		*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH_W, HEIGHT_W, "Fdf");
	e->img = mlx_new_image(e->mlx, WIDTH_W, HEIGHT_W);
	e->data = NULL;
	e->points = NULL;
	e->scale = 0.5;
	e->cam.x = 0;
	e->cam.y = 0;
	e->cam.z = 0;
	e->bpp = 0;
	e->sline = 0;
	e->endian = 0;
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sline, &e->endian);
	e->color = 0x00FFFFFF;
	return (e);
}

void		delete_env(t_env *e)
{
	int		i[2];

	i[0] = 0;
	if (!e)
		return ;
	if (e->mlx)
		free(e->mlx);
	if (e->win)
		free(e->win);
	if (e->img)
		free(e->img);
	if (e->points)
	{
		while (i[0] < e->nb_line)
		{
			i[1] = 0;
			while (i[1] < e->size[i[0]])
				free(e->points[i[0]][i[1]++]);
			i[0]++;
		}
	}
	if (e->size)
		free(e->size);
	free(e);
}
