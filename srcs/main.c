#include "../includes/fdf.h"

void		init_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
	point->color = 0;
	//point->next = NULL;
}

void		init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->width = 500;
	env->height = 500;
	env->title = "Fil de fer";
	env->win = mlx_new_window(env->mlx, env->width, env->height, env->title);
	if (!env->win)
	{
		mlx_clear_window(env->mlx, env->win);
		mlx_destroy_window(env->mlx, env->win);
	}
}

int			main()
{
	t_env		env;
	t_point 	point;

	init_env(&env);
	init_point(&point);
	point.x = 50;
	while (point.x < 100)
	{
		point.y = 50;
		while (point.y < 100)
		{
			point.color = 0x00FF00FF;
			mlx_pixel_put(env.mlx, env.win, point.x, point.y, point.color);
			point.y++;
		}
		point.x++;
	}
	mlx_loop(env.mlx);
}
