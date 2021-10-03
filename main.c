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


void ft_print_available_params()
{
	write(2, "Available params:\n julia; mandelbrot;\n", 39);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_vars	vars_mlx;
	
	vars_mlx.zoom = 1;
	if (argc != 2)
		ft_print_available_params();
	vars_mlx.mlx = mlx_init(); 
	vars_mlx.win = mlx_new_window(vars_mlx.mlx, WIDHT, HEIGHT, "fractal");
	if (!ft_strncmp(argv[1], "julia", 8))
	{
		vars_mlx.name = 'j';
		vars_mlx.dx = 0.285;
		vars_mlx.dy = 0.01;
		ft_julia(&vars_mlx);
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		vars_mlx.name = 'm';
		vars_mlx.dx = -0.5;
		vars_mlx.dy = 0;
		ft_mandelbrot(&vars_mlx);
	}
	else
		ft_print_available_params();
	// printf("%c", vars_mlx.name);
	// ft_init_struct(&vars_mlx);
	// ft_mandelbrot(&vars_mlx);
	// ft_julia(&vars_mlx);
	mlx_hook(vars_mlx.win, 2, 0, mlx_exit, &vars_mlx);
	mlx_hook(vars_mlx.win, 4, 0, ft_zoom, &vars_mlx);
	// mlx_hook(vars_mlx.win, 4, 4L, ft_mouse, &vars_mlx);
	mlx_loop(vars_mlx.mlx);



	// for (int i = 0; i < 35; i++)
	// 	printf("%3d ", rand() % 255);
	 

	return (0);
}
