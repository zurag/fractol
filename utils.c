#include "fractol.h"

void ft_init_fractol(t_fractol *fractal)
{
	fractal->dx = -0.5;
	fractal->dy = 0;
	fractal->new_z_im = 0;
	fractal->new_z_real = 0;
	fractal->old_z_im = 0;
	fractal->old_z_real = 0;
	fractal->zoom = 1;
}

void ft_launch_fractal(t_vars *vars_mlx)
{
	if (vars_mlx->name == 'j')
		ft_julia(vars_mlx);
	else if (vars_mlx->name == 'm')
		ft_mandelbrot(vars_mlx);
	else if (vars_mlx->name == 'b')
		ft_burning_ship(vars_mlx);
}