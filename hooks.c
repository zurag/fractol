/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:31:25 by zurag             #+#    #+#             */
/*   Updated: 2021/10/10 19:31:26 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mlx_key(int key_code, t_vars *vars_mlx)
{
	if (key_code == 53)
	{
		mlx_destroy_window(vars_mlx->mlx, vars_mlx->win);
		exit(0);
	}
	else if (key_code == 126)
		vars_mlx->fractal.dy -= 10;
	else if (key_code == 125)
		vars_mlx->fractal.dy += 10;
	else if (key_code == 124)
		vars_mlx->fractal.dx += 10;
	else if (key_code == 123)
		vars_mlx->fractal.dx -= 10;
	else if (key_code >= 18 && key_code <= 23)
		vars_mlx->fractal.color = key_code;
	else if (key_code == 12)
		vars_mlx->fractal.max_iter += 10;
	else if (key_code == 13)
		vars_mlx->fractal.max_iter -= 10;
	ft_fractal(vars_mlx);
	return (1);
}

int	ft_zoom(int key_code, int x, int y, t_vars *vars_mlx)
{
	if (key_code == 5)
	{
		vars_mlx->fractal.zoom *= 1.1;
		vars_mlx->fractal.dx += \
			(double)(x - WIDHT / 2 + vars_mlx->fractal.dx) *0.1;
		vars_mlx->fractal.dy += \
			(double)(HEIGHT / 2 - y + vars_mlx->fractal.dy) *0.1;
	}
	else if (key_code == 4)
	{
		vars_mlx->fractal.dx -= \
			(double)(x - WIDHT / 2 + vars_mlx->fractal.dx) *0.1;
		vars_mlx->fractal.dy -= \
			(double)(HEIGHT / 2 - y + vars_mlx->fractal.dy) *0.1;
		vars_mlx->fractal.zoom *= 0.9;
	}
	else
		return (-1);
	ft_fractal(vars_mlx);
	return (1);
}

int	ft_mouse(int x, int y, t_vars *vars_mlx)
{
	if (vars_mlx->name == 'j')
	{
		vars_mlx->fractal.const_im = (x - WIDHT / (double)2) / 500.f;
		vars_mlx->fractal.const_real = ((HEIGHT / 2) - (double)y) / 500.f;
		vars_mlx->fractal.flag_j = 0;
		ft_fractal(vars_mlx);
	}
	return (1);
}
