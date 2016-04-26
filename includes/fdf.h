/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 01:49:25 by wgulista          #+#    #+#             */
/*   Updated: 2016/04/20 01:50:59 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

# define UP 65
# define DOWN 66
# define RIGHT 67
# define LEFT 68

typedef struct		s_point
{
	int				x;
	int				y;
	int				color;
	//t_point			*next;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*title;
	int				width;
	int				height;
}					t_env;



#endif
