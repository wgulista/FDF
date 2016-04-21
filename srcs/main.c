#include "../includes/fdf.h"

int		main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();

	win = mlx_new_window(mlx, 500, 500, "Fil de fer");
	mlx_loop(mlx);
}