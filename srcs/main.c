/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:13:39 by wgulista          #+#    #+#             */
/*   Updated: 2016/07/12 16:14:01 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_env		*parse_map(char *file, t_env **e)
{
	t_line			*head;
	char			*line;
	int				fd;

	line = NULL;
	head = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putstr(file);
		ft_malloc_error(" - Filename could not open !");
	}
	while (get_next_line(fd, &line) > 0)
	{
		line_push_back(&head, new_line(line));
		line = NULL;
		(*e)->nb_line++;
	}
	*e = initpoints(*e, &head);
	if (close(fd) == -1)
		ft_malloc_error("Close file failed !");
	return (*e);
}

int					main(int ac, char **av)
{
	t_env			*e;

	if (ac == 2)
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			ft_malloc_error("Memory allocation for ENV failed !");
		if (!(e = init_env()))
			ft_malloc_error("EXIT_FAILURE");
		parse_map(av[1], &e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, 2, 3, keyhook, e);
		mlx_loop(e->mlx);
		delete_env(e);
	}
	else
		ft_usage_error();
	return (0);
}
