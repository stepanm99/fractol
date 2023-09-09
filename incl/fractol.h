/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:48 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/09 16:30:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

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

/*
-----------------Madelbrot set data struct-----------------
div_x, div_y	<-- width of complex plane divided by width in pixels
					=> width of an pixel on a complex plane
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
	double		div_x;
	double		div_y;
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
-----------------Program data struct-----------------
width, height	<-- of the picture in pixels
*/
typedef struct dt
{
	int			width;
	int			height;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_man_dat	*man_dat;
}	t_dt;

/*Program functions*/
void		ft_key_control(t_man_dat *man_dat);

/*Functions for mandelbrot*/
void		ft_com_num_init(t_com_num *com_num, double real, double imag);
t_com_num	ft_com_multiplication(t_com_num num1, t_com_num num2);
t_com_num	ft_com_sum(t_com_num num1, t_com_num num2);
double		ft_com_abs_value(t_com_num num);
void		ft_mandel_iteration(t_man_dat *man_dat);
void		ft_mandel_comp(t_man_dat *man_dat);
void		ft_mandel_inside_color(t_man_dat *man_dat);
void		ft_mandel_outside_color(t_man_dat *man_dat);
void		*ft_man_dat_init(t_dt *dt);
t_dt		*ft_dt_init(void);

#endif