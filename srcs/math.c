/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:11 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:13 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double				ft_degre_to_radian(double degre)
{
	while (degre > 360)
		degre -= 360;
	while (degre < 360)
		degre += 360;
	return (degre * PI / 180);
}

double				ft_cos(double angle)
{
	return (cos(ft_degre_to_radian(angle)));
}

double				ft_sin(double angle)
{
	return (sin(ft_degre_to_radian(angle)));
}

unsigned int		ft_abs(int num)
{
	unsigned int	r;
	int				mask;

	mask = num >> (sizeof(int) * 8 - 1);
	r = (num + mask) ^ mask;
	return (r);
}

unsigned int		ft_max(int a, int b)
{
	return ((a + b) / 2);
}
