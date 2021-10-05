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

	// printf("x == %d, y == %d\n", x, y);
	if (key_code == 5)
	{
		vars_mlx->fractal.zoom *= 1.1;
		vars_mlx->fractal.max_iter += 2;
		vars_mlx->fractal.dx +=  (double)(x - WIDHT / 2 + vars_mlx->fractal.dx) * 0.1 ;
		vars_mlx->fractal.dy += (double)(HEIGHT / 2 - y + vars_mlx->fractal.dy) * 0.1 ;
	}
	else if (key_code == 4)
	{
		vars_mlx->fractal.dx -= (double)(x - WIDHT / 2 + vars_mlx->fractal.dx) * 0.1;
		vars_mlx->fractal.dy -= (double)(HEIGHT / 2 - y + vars_mlx->fractal.dy) * 0.1;
		if (vars_mlx->fractal.max_iter > 2)
			vars_mlx->fractal.max_iter -= 2;
		vars_mlx->fractal.zoom *= 0.9;
	}
	else
		return (-1);
	if (vars_mlx->name == 'j')
		ft_julia(vars_mlx);
	else if (vars_mlx->name == 'm')
		ft_mandelbrot(vars_mlx);
	return (1);
}

int	ft_mouse(int x, int y, t_vars *vars_mlx)
{
	if (vars_mlx->name == 'j')
	{
		vars_mlx->fractal.const_im = (x - WIDHT / (double)2) / 500.f;
		vars_mlx->fractal.const_real = (HEIGHT / 2 - (double)y) / 500.f;
		vars_mlx->fractal.flag_j = 0;
		ft_julia(vars_mlx);
	}
	return (1);
}
