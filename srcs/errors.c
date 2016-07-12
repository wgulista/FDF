/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:13:13 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:13:16 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_usage_error(void)
{
	ft_putendl("Usage: ./fdf [filename]");
	exit(0);
}

void		ft_map_error(void)
{
	ft_putendl("Map error !");
	exit(0);
}

void		ft_malloc_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}
