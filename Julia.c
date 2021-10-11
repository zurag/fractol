/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:31:32 by zurag             #+#    #+#             */
/*   Updated: 2021/10/10 19:31:33 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_fractol *fractal, int x, int y)
{
	int	i;

	i = 0;
	fractal->new_z_real = 1.5 * (x - WIDHT / 2 + fractal->dx) \
		/ (0.5 * fractal->zoom * WIDHT);
	fractal->new_z_im = (y - HEIGHT / 2 + fractal->dy) \
		/ (0.5 * fractal->zoom * HEIGHT);
	while (i < fractal->max_iter)
	{
		fractal->old_z_real = fractal->new_z_real;
		fractal->old_z_im = fractal->new_z_im;
		fractal->new_z_real = fractal->old_z_real * fractal->old_z_real \
			- fractal->old_z_im * fractal->old_z_im + fractal->const_real;
		fractal->new_z_im = 2 * fractal->old_z_real * fractal->old_z_im \
			+ fractal->const_im;
		if ((fractal->new_z_real * fractal->new_z_real + fractal->new_z_im \
			* fractal->new_z_im) > 4)
			break ;
		i++;
	}
	return (i);
}
