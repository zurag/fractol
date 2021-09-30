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
