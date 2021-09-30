#include "fractol.h"

int	mlx_exit(int key_code, t_vars *vars_mlx)
{
	if (key_code == 53)
	{
		mlx_destroy_window(vars_mlx->mlx, vars_mlx->win);
		exit(0);
	}
	return (1);
}

int	ft_zoom(int key_code, int x, int y, t_vars *vars_mlx)
{
	(void)x;
	(void)y;
	if (key_code == 5)
		vars_mlx->zoom += 0.5;
	else if (key_code == 4)
		vars_mlx->zoom -= 0.5;
	else
		return (1);
	ft_mandelbrot(vars_mlx);
	// ft_julia(vars_mlx);
	return (1);
}
