/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:48 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/27 19:56:20 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../ft_printf/incl/ft_printf.h"

/*Struct for storing complex number*/
typedef struct com_num
{
	double	real;
	double	imag;
}	t_com_num;

/*Struct for storing mandelbrot numbers for compputation*/
typedef struct man_num
{
	t_com_num	z;
	t_com_num	c;
}	t_man_num;

typedef struct man_col
{
	int	r_coef;
	int	g_coef;
	int	b_coef;
}	t_man_col;

/*
-----------------Madelbrot set data struct-----------------
used also for computing Julia set

div_x, div_y	<-- width of complex plane divided by width in pixels
					=> width of an pixel on a complex plane
jul_x, jul_y	<-- complex plane coordinates for computing Julia set
x, y			<-- complex plane coordinates to shift image in the plane
zoom			<-- zoom
width, height	<-- of the picture in pixels
x_c, y_c		<-- complex plane coordinates of the point that is
					currently computed
iter			<-- limit number of iterations for each point
i				<-- index variable for iterations
*/
typedef struct man_dat
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_man_num	man_num;
	t_man_col	man_col;
	double		div_x;
	double		div_y;
	double		jul_x;
	double		jul_y;
	double		x;
	double		y;
	double		zoom;
	int			width;
	int			height;
	int			x_c;
	int			y_c;
	int			iter;
	int			i;
}	t_man_dat;

/*
-----------------Newton fractal data struct-----------------
z				<-- complex number to compute with
func_res		<-- result of normal function
deri_res		<-- result of derivative of the former function
roots[3]		<-- array with roots of the polynom
tolerance		<-- of the points' distance from root
iter			<-- limit of iterations
i				<-- current iteration
*/
typedef struct new_dat
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_com_num	z;
	t_com_num	func_res;
	t_com_num	deri_res;
	t_com_num	three;
	t_com_num	roots[3];
	double		div_x;
	double		div_y;
	double		x;
	double		y;
	double		zoom;
	double		tolerance;
	int			width;
	int			height;
	int			x_c;
	int			y_c;
	int			iter;
	int			i;
	int			c_i;
}	t_new_dat;

/*
-----------------Program data struct-----------------
width, height	<-- of the picture in pixels
fr_flag			<-- flag for fractal type
					1 = Mandelbrot
					2 = Julia
					3 = Newton
*/
typedef struct dt
{
	int			width;
	int			height;
	double		jul_x;
	double		jul_y;
	char		fr_flag;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_man_dat	*man_dat;
	t_new_dat	*new_dat;
}	t_dt;

/*-----Program functions-----*/
t_dt		*ft_dt_init(void);
void		ft_data_free(t_dt *dt);
void		ft_key_control(void *param);
void		ft_scroll(double xdelta, double ydelta, void *param);
double		ft_atof(const char *str, t_dt *dt);
int			ft_match(const char *str1, const char *str2);
void		ft_fr_dat_init(t_dt *dt);
void		ft_put_fractal(t_dt *dt);

/*-----Error & help functions-----*/
/*ft_error: errno
	0 -> number error (e.g.: in arg for Julia)*/
void		ft_error(int errno, t_dt *dt);
void		ft_print_nr_error(t_dt *dt);
void		ft_print_help(t_dt *dt);

/*-----Functions for working with complex numbers-----*/
void		ft_com_num_init(t_com_num *com_num, double real, double imag);
t_com_num	ft_com_multiplication(t_com_num num1, t_com_num num2);
t_com_num	ft_com_division(t_com_num den, t_com_num div);
t_com_num	ft_com_pow(t_com_num num, int pow);
t_com_num	ft_com_sum(t_com_num num1, t_com_num num2);
t_com_num	ft_com_subtraction(t_com_num num1, t_com_num num2);
double		ft_com_abs_value(t_com_num num);

/*-----Functions for Mandelbrot set-----*/
void		ft_man_dat_init(t_dt *dt);
void		ft_mandel_comp(t_dt *dt);
void		ft_mandel_iteration(t_man_dat *man_dat);
void		ft_mandel_inside_color(t_man_dat *man_dat);
void		ft_mandel_outside_color(t_man_dat *man_dat);
void		ft_mandel_color_rand(t_man_dat *man_dat);

/*-----Functions for Julia set-----*/
void		ft_jul_comp(t_dt *dt);
void		ft_get_jul(t_man_dat *man_dat);

/*-----Functions for Newton fractal-----*/
void		ft_new_dat_init(t_dt *dt);
void		ft_new_comp(t_dt *dt);
void		ft_new_iter(t_new_dat *new_dat);

#endif