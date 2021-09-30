#include "fractol.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// static	int ft_create_color(int i)
// {	
// 	return (create_trgb(0, (3 * sin(i) + 100), (60 * sin(i) + 150), (10 * sin(i) + 200)));
// }

// void	ft_mandelbrot(t_vars *vars_mlx)
// {
// 	int	max_iter;
// 	// int	color = 0x000000FF;
// 	int	x;
// 	int	y;
// 	int i;
// 	double	rpixel, ipixel;
// 	double	newRe, newIm, oldRe, oldIm;
// 	double	moveX = -0.5, moveY = 0;
// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	max_iter = 150;

// 	vars_mlx->img = mlx_new_image(vars_mlx->mlx, WIDHT, HEIGHT);
// 	vars_mlx->addr = mlx_get_data_addr(vars_mlx->img, &(vars_mlx->bits_per_pixel), & (vars_mlx->line_length), & (vars_mlx->endian));		
// 	while (y < HEIGHT)
// 	{
// 		while (x < WIDHT)
// 		{
// 			rpixel = 1.5 * ( x - WIDHT / 2) / (0.5 * vars_mlx->zoom * WIDHT) + moveX;
// 			ipixel = (y - HEIGHT / 2) / (0.5 * vars_mlx->zoom * HEIGHT) + moveY;
// 			newRe = newIm = oldRe = oldIm = 0;
// 			while (i < max_iter)
// 			{
// 				oldRe = newRe;
// 				oldIm = newIm;
// 				newRe = oldRe * oldRe - oldIm * oldIm + rpixel;
//       			newIm = 2 * oldRe * oldIm + ipixel;
// 				if ((newRe * newRe + newIm * newIm) > 4)
// 					break;
// 				i++;
// 			}
// 			if (pow(newIm, 2)  + pow(newRe, 2) <= 4)
// 				my_mlx_pixel_put(vars_mlx, x, y, 0);
// 			else
// 				my_mlx_pixel_put(vars_mlx, x, y, ft_create_color(i));
// 			i = 0;
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	mlx_put_image_to_window(vars_mlx->mlx, vars_mlx->win, vars_mlx->img, 0, 0);
// 	mlx_destroy_image(vars_mlx->mlx, vars_mlx->img);
// }

// static void ft_init_struct(t_vars *vars_mlx)
// {
// 	vars_mlx->zoom = 1;
// 	vars_mlx->mlx = mlx_init(); 
// 	vars_mlx->win = mlx_new_window(vars_mlx->mlx, WIDHT, HEIGHT, "Mandelbrot");
// 	vars_mlx->img = mlx_new_image(vars_mlx->mlx, WIDHT, HEIGHT);
// 	vars_mlx->addr = mlx_get_data_addr(vars_mlx->img, &(vars_mlx->bits_per_pixel), &(vars_mlx->line_length), &(vars_mlx->endian));
// }


int	main()
{
	t_vars	vars_mlx;
	
	vars_mlx.zoom = 1;
	
	vars_mlx.dx = 0;
	vars_mlx.dy = 0;

	vars_mlx.mlx = mlx_init(); 
	vars_mlx.win = mlx_new_window(vars_mlx.mlx, WIDHT, HEIGHT, "Mandelbrot");
	// ft_init_struct(&vars_mlx);
	ft_mandelbrot(&vars_mlx);
	// ft_julia(&vars_mlx);
	mlx_hook(vars_mlx.win, 2, 0, mlx_exit, &vars_mlx);
	// mlx_mouse_hook(vars_mlx.win, ft_zoom, &vars_mlx);
	mlx_hook(vars_mlx.win, 4, 0, ft_zoom, &vars_mlx);
	mlx_loop(vars_mlx.mlx);
	return (0);
}
