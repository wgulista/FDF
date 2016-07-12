/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:47 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:55 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->scale += 0.1;
}

void	dezoom(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->scale -= 0.1;
}
