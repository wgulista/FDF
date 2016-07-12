/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:26 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:27 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		ft_get_point(t_env *e, t_point *pt,
	t_point (*f)(double, double, double))
{
	t_point		new;

	new.x = (double)(WIDTH_W + pt->x * 20 * e->scale);
	new.y = (double)(HEIGHT_W + pt->y * 20 * e->scale);
	new.z = (double)(pt->z * e->scale);
	new = (*f)(new.x, new.y, new.z);
	return (new);
}

t_env		*initpoints(t_env *e, t_line **head)
{
	t_line	*tmp;
	int		elem;

	elem = 0;
	e->points = (t_point ***)malloc(sizeof(t_point **) * e->nb_line);
	if (!e->points)
		return (NULL);
	if (!(e->size = (int *)malloc(sizeof(int) * e->nb_line)))
		return (NULL);
	e->nb_line = 0;
	while (*head)
	{
		e->points[e->nb_line] = splitter((*head)->line, e->nb_line, &elem);
		e->size[e->nb_line++] = elem;
		tmp = *head;
		*head = (*head)->next;
		if (tmp)
		{
			free(tmp->line);
			free(tmp);
		}
	}
	return (e);
}
