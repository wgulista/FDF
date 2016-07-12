/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:30 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:37 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		ft_iso(double x, double y, double z)
{
	t_point		pt;
	double		ct1;
	double		ct2;

	ct1 = 0.5;
	ct2 = 0.5;
	pt.x = (ct1 * x) - (ct2 * y);
	pt.y = -z + ((ct1 / 2) * x) + ((ct2 / 2) * y);
	pt.z = z;
	return (pt);
}

t_point		ft_para(double x, double y, double z)
{
	t_point		pt;
	double		ct1;

	ct1 = 0.8;
	pt.x = x + (ct1 * z);
	pt.y = y + ((ct1 / 2) * z);
	pt.z = z;
	return (pt);
}
