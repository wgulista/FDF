/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:14:39 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:41 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static unsigned int		ft_num(char const *s)
{
	int				i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && !(ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-'))
			i++;
		if (s[i])
		{
			while (s[i] && (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-'))
				i++;
			size++;
		}
	}
	return (size);
}

static char				**split_fdf(char const *s, int *nb_elem)
{
	char			**tab;
	unsigned int	size;
	unsigned int	start;
	int				i;

	*nb_elem = ft_num(s);
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (*nb_elem + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if ((ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-'))
		{
			start = i;
			while (s[i] && (ft_isdigit(s[i]) || s[i] == '+' || s[i] == '-'))
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
		else
			i++;
	}
	tab[size] = 0;
	return (tab);
}

t_point					**splitter(char const *s, int nb_line, int *nb_elem)
{
	t_point		**line;
	char		**tab;
	int			i;

	i = 0;
	tab = split_fdf(s, nb_elem);
	if (!(line = (t_point **)malloc(sizeof(t_point *) * *nb_elem)))
		return (NULL);
	while (i < *nb_elem)
	{
		if (!(line[i] = (t_point *)malloc(sizeof(t_point))))
			return (NULL);
		line[i]->x = i;
		line[i]->y = nb_line;
		if (ft_atoi(tab[i]) < -3)
			line[i]->z = ft_atoi(tab[i]) * 3;
		else
			line[i]->z = ft_atoi(tab[i]) * 5;
		i++;
	}
	return (line);
}
