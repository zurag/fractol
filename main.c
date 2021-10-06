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
	write(2, "Available params: julia; mandelbrot; burning_ship;\n", 52);
	exit(1);
}


void	ft_init_fractal(t_vars *vars_mlx, char *name)
{
	if (!ft_strncmp(name, "julia", 8))
	{
		vars_mlx->name = 'j';
		vars_mlx->fractal.dx = 0.285;
		vars_mlx->fractal.dy = 0.01;
		ft_julia(vars_mlx);
	}
	else if (!ft_strncmp(name, "mandelbrot", 11))
	{
		vars_mlx->name = 'm';
		vars_mlx->fractal.dx = -100;
		vars_mlx->fractal.dy = 0;
		ft_mandelbrot(vars_mlx);
	}
	else if (!ft_strncmp(name, "burning_ship", 13))
	{
		vars_mlx->name = 'b';
		vars_mlx->fractal.dx = 100;
		vars_mlx->fractal.dy = 100;
		ft_burning_ship(vars_mlx);
	}
	else
		ft_print_available_params();
}


int	main(int argc, char **argv)
{
	t_vars	vars_mlx;
	
	vars_mlx.fractal.flag_j = 1;
	vars_mlx.fractal.zoom = 0.8;
	vars_mlx.fractal.max_iter = 50;
	if (argc != 2)
		ft_print_available_params();
	vars_mlx.mlx = mlx_init(); 
	vars_mlx.win = mlx_new_window(vars_mlx.mlx, WIDHT, HEIGHT, "fractal");
	ft_init_fractal(&vars_mlx, argv[1]);
	mlx_hook(vars_mlx.win, 2, 0, mlx_key, &vars_mlx);
	mlx_hook(vars_mlx.win, 4, 0, ft_zoom, &vars_mlx);
	if (vars_mlx.name == 'j')
		mlx_hook(vars_mlx.win, 6, 1L<<6, ft_mouse, &vars_mlx);
	mlx_loop(vars_mlx.mlx);
	return (0);
}
