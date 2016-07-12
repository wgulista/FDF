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
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>

# define PI	3.14159265
# define SEP 20
# define WIDTH_W 1000
# define HEIGHT_W 800

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				nb_line;
	int				*size;
	float			scale;
	t_point			cam;
	t_point			***points;
	int				bpp;
	int				sline;
	int				endian;
	char			*data;
	int				color;
}					t_env;

void				ft_usage_error();
void				ft_map_error();
void				ft_malloc_error(char *msg);

unsigned int		ft_abs(int n);
unsigned int		ft_max(int a, int b);
double				ft_cos(double angle);
double				ft_sin(double angle);

t_env				*init_env(void);
void				delete_env(t_env *e);

void				draw_bresenham(t_env *e, t_point p1, t_point p2);

t_point				ft_iso(double x, double y, double z);
t_point				ft_para(double x, double y, double z);

t_env				*initpoints(t_env *e, t_line **head);
t_point				ft_get_point(t_env *e, t_point *pt,
	t_point (*f)(double, double, double));

t_line				*new_line(char *line);
t_line				*line_push_back(t_line **head, t_line *new);

void				mlx_pixel_put_image(t_env *e, int x, int y, int color);
void				draw_map(t_env *e);

t_point				**splitter(char const *s, int nb_line, int *nb_elem);

void				move_pixel_to_left(t_env *env);
void				move_pixel_to_bottom(t_env *env);
void				move_pixel_to_right(t_env *env);
void				move_pixel_to_top(t_env *env);

void				zoom(t_env *env);
void				dezoom(t_env *env);

int					keyhook(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				mlx_pixel_put_image(t_env *e, int x, int y, int color);

int					main(int ac, char **av);

#endif
