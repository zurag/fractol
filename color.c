/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:31:40 by zurag             #+#    #+#             */
/*   Updated: 2021/10/10 19:31:41 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_calc(int iter, int max, int scheme)
{
	int		s1;
	int		s2;
	int		s3;

	s1 = scheme / 100;
	s2 = (scheme / 10) % 10;
	s3 = scheme % 10;
	if (iter <= max / 2)
		return ((255 / (max / 2 - iter + 1)) << (s1 * 8));
	else
		return (255 << (s1 * 8) | (int)(255 * (iter - max / 2 + 1) \
					/ (max / 2)) << (s2 * 8) | (int)(255 * ((iter - max
							/ 2 + 1) / (max / 2))) << (s3 * 8));
	return (0);
}

int	ft_create_color(int i, t_vars *vars_mlx)
{
	if (pow(vars_mlx->fractal.new_z_im, 2) + \
		pow(vars_mlx->fractal.new_z_real, 2) <= 4)
		return (0);
	else if (vars_mlx->fractal.color == 18)
		return (12345678 * i);
	else if (vars_mlx->fractal.color == 19)
		return (ft_color_calc(i, vars_mlx->fractal.max_iter, 12));
	else if (vars_mlx->fractal.color == 20)
		return (ft_color_calc(i, vars_mlx->fractal.max_iter, 120));
	else if (vars_mlx->fractal.color == 21)
		return (ft_color_calc(i, vars_mlx->fractal.max_iter, 210));
	else if (vars_mlx->fractal.color == 22)
		return (ft_color_calc(i, vars_mlx->fractal.max_iter, 12));
	else if (vars_mlx->fractal.color == 23)
		return (255 * i / vars_mlx->fractal.max_iter \
			| (255 * i / vars_mlx->fractal.max_iter) << 8 \
			| (255 * i / vars_mlx->fractal.max_iter) << 16);
	else
		return (12345678 * i);
}
