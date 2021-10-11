/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:31:27 by zurag             #+#    #+#             */
/*   Updated: 2021/10/10 19:31:28 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_fractal_vars(t_vars *mlx)
{
	mlx->fractal.new_z_im = 0;
	mlx->fractal.new_z_real = 0;
	mlx->fractal.old_z_im = 0;
	mlx->fractal.old_z_real = 0;
	if (mlx->name != 'j')
	{
		mlx->fractal.const_im = 0;
		mlx->fractal.const_real = 0;
	}
	if (mlx->fractal.flag_j)
	{
		mlx->fractal.const_im = 0.156;
		mlx->fractal.const_real = -0.8;
	}
}

void	ft_fractal(t_vars *mlx)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	ft_init_fractal_vars(mlx);
	mlx->img = mlx_new_image(mlx->mlx, WIDHT, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel), \
			&(mlx->line_length), & (mlx->endian));
	while (y < HEIGHT)
	{
		while (x < WIDHT)
		{
			i = ft_launch_fractal(mlx, x, y);
			my_mlx_pixel_put(mlx, x, y, ft_create_color(i, mlx));
			i = 0;
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}

int	ft_launch_fractal(t_vars *vars_mlx, int x, int y)
{
	if (vars_mlx->name == 'j')
		return (ft_julia(&vars_mlx->fractal, x, y));
	else if (vars_mlx->name == 'm')
		return (ft_mandelbrot(&vars_mlx->fractal, x, y));
	else if (vars_mlx->name == 'b')
		return (ft_burning_ship(&vars_mlx->fractal, x, y));
	else
		return (-1);
}
