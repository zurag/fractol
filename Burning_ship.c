/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:31:17 by zurag             #+#    #+#             */
/*   Updated: 2021/10/10 19:31:35 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_burning_ship(t_fractol *fractal, int x, int y)
{
	int	i;

	i = 0;
	fractal->const_real = \
		1.5 * (x + fractal->dx - WIDHT / 2) / (0.5 * fractal->zoom * WIDHT);
	fractal->const_im = \
		(y + fractal->dy - HEIGHT / 2) / (0.5 * fractal->zoom * HEIGHT);
	fractal->new_z_im = 0;
	fractal->new_z_real = 0;
	fractal->old_z_im = 0;
	fractal->old_z_real = 0;
	while (i < fractal->max_iter)
	{
		fractal->old_z_real = fractal->new_z_real;
		fractal->old_z_im = fractal->new_z_im;
		fractal->new_z_real = (fractal->old_z_real * fractal->old_z_real \
			 - fractal->old_z_im * fractal->old_z_im) - fractal->const_real;
		fractal->new_z_im = 2 * fabs(fractal->old_z_real * fractal->old_z_im) \
		+ fractal->const_im;
		if ((fractal->new_z_real * fractal->new_z_real + fractal->new_z_im \
			* fractal->new_z_im) > 10)
			break ;
		i++;
	}
	return (i);
}
