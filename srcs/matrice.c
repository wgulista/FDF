/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:17 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:20 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrice	*rot_x(double num, t_env *e)
{
	t_matrice	*m;

	(void)e;
	if (!(m = (t_matrice*)malloc(sizeof(t_matrice))))
		ft_malloc_error("Memory allocation for MATRICE X failed !");
	m->a1 = 1;
	m->a2 = 0;
	m->a3 = 0;
	m->b1 = 0;
	m->b2 = ft_cos(num);
	m->b3 = -ft_sin(num);
	m->c1 = 0;
	m->c2 = ft_sin(num);
	m->c3 = ft_cos(num);
	return (m);
}

t_matrice	*rot_y(double num, t_env *e)
{
	t_matrice	*m;

	(void)e;
	if (!(m = (t_matrice*)malloc(sizeof(t_matrice))))
		ft_malloc_error("Memory allocation for MATRICE Y failed !");
	m->a1 = ft_cos(num);
	m->a2 = 0;
	m->a3 = ft_sin(num);
	m->b1 = 0;
	m->b2 = 1;
	m->b3 = 0;
	m->c1 = -ft_sin(num);
	m->c2 = 0;
	m->c3 = ft_cos(num);
	return (m);
}

t_matrice	*rot_z(double num, t_env *e)
{
	t_matrice	*m;

	(void)e;
	if (!(m = (t_matrice*)malloc(sizeof(t_matrice))))
		ft_malloc_error("Memory allocation for MATRICE Z failed !");
	m->a1 = ft_cos(num);
	m->a2 = -ft_sin(num);
	m->a3 = 0;
	m->b1 = ft_sin(num);
	m->b2 = ft_cos(num);
	m->b3 = 0;
	m->c1 = 0;
	m->c2 = 0;
	m->c3 = 1;
	return (m);
}

t_matrice	*translation(double tx, double ty, double tz)
{
	t_matrice	*m;

	if (!(m = (t_matrice*)malloc(sizeof(t_matrice))))
		ft_malloc_error("Memory allocation for MATRICE failed !");
	(void)tx;
	(void)ty;
	(void)tz;
	return (m);
}
