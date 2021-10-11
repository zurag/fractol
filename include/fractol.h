/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:31:44 by zurag             #+#    #+#             */
/*   Updated: 2021/10/10 19:31:45 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDHT	800 
# define HEIGHT	600

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

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
	int		color;
}				t_fractol;

typedef struct s_vars {
	char		name;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_fractol	fractal;
}				t_vars;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		ft_mandelbrot(t_fractol *fractal, int x, int y);
int		ft_zoom(int key_code, int x, int y, t_vars *vars_mlx);
int		ft_mouse(int x, int y, t_vars *vars_mlx);
int		mlx_key(int key_code, t_vars *vars_mlx);
int		create_trgb(int t, int r, int g, int b);
int		ft_create_color(int i, t_vars *vars_mlx);
int		ft_julia(t_fractol *fractal, int x, int y);
int		ft_burning_ship(t_fractol *fractal, int x, int y);
int		ft_launch_fractal(t_vars *vars_mlx, int x, int y);
void	ft_fractal(t_vars *mlx);

#endif