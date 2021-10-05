#ifndef FRACTOL_H
 #define FRACTOL_H

#define WIDHT	800 
#define HEIGHT	600

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_fractol {
	double	zoom;
	double	dx;
	double	dy;
	int		flag_j;
	int		max_iter;
	double	new_z_real;
	double	new_z_im;
	double	old_z_real;
	double	old_z_im;
	double	const_real;
	double	const_im;
}				t_fractol;

typedef struct	s_vars {
	char		name;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int 		line_length;
	int			endian;
	t_fractol	fractal;
}				t_vars;


void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void	ft_mandelbrot(t_vars *vars_mlx);
int		ft_zoom(int key_code, int x, int y, t_vars *vars_mlx);
int		ft_mouse(int x, int y, t_vars *vars_mlx);
int		mlx_key(int key_code, t_vars *vars_mlx);
int		create_trgb(int t, int r, int g, int b);
int		ft_create_color(int i);
void	ft_julia(t_vars *vars_mlx);


#endif