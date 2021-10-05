#include "fractol.h"

void ft_init_julia(t_fractol *fractal)
{
	fractal->new_z_im = 0;
	fractal->new_z_real = 0;
	fractal->old_z_im = 0;
	fractal->old_z_real = 0;
	if (fractal->flag_j)
	{
		fractal->const_real = -0.8;
		fractal->const_im = 0.156;
	}
}

static int	calculate_z(t_fractol *fractal, int x, int y)
{
	int i;

	i = 0;
	fractal->new_z_real = 1.5 * ( x - WIDHT / 2 + fractal->dx) / (0.5 * fractal->zoom * WIDHT) ;
	fractal->new_z_im = (y - HEIGHT / 2 + fractal->dy) / (0.5 * fractal->zoom * HEIGHT);
	while (i < fractal->max_iter)
	{
		fractal->old_z_real = fractal->new_z_real;
		fractal->old_z_im = fractal->new_z_im;
		fractal->new_z_real = fractal->old_z_real * fractal->old_z_real - fractal->old_z_im * fractal->old_z_im + fractal->const_real;
		fractal->new_z_im = 2 * fractal->old_z_real * fractal->old_z_im + fractal->const_im;
		if ((fractal->new_z_real * fractal->new_z_real + fractal->new_z_im * fractal->new_z_im) > 4)
			break;
		i++;
	}
	return (i);
}

void ft_julia(t_vars *vars_mlx)
{
	int	x;
	int	y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	ft_init_julia(&vars_mlx->fractal);
	vars_mlx->img = mlx_new_image(vars_mlx->mlx, WIDHT, HEIGHT);
	vars_mlx->addr = mlx_get_data_addr(vars_mlx->img, &(vars_mlx->bits_per_pixel), & (vars_mlx->line_length), & (vars_mlx->endian));		
	while (y < HEIGHT)
	{
		while (x < WIDHT)
		{
			i = calculate_z(&vars_mlx->fractal, x, y);
			if (pow(vars_mlx->fractal.new_z_im, 2)  + pow(vars_mlx->fractal.new_z_real, 2) <= 4)
				my_mlx_pixel_put(vars_mlx, x, y, 0);
			else
				my_mlx_pixel_put(vars_mlx, x, y, ft_create_color(i));
			i = 0;
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(vars_mlx->mlx, vars_mlx->win, vars_mlx->img, 0, 0);
	mlx_destroy_image(vars_mlx->mlx, vars_mlx->img);
}
