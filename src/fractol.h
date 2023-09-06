/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:48 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/06 19:37:16 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "../MLX42/include/MLX42/MLX42.h"

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

/*Madelbrot set data struct*/
typedef struct man_dat
{
	mlx_t		*mlx;
	t_man_num	man_num;
	double		div_x;
	double		div_y;
	double		x;
	double		y;
	double		zoom;
	int			x_c;
	int			y_c;
	int			iter;
	int			i;
}	t_man_dat;

/*Math functions for mandelbrot*/
void		com_num_init(t_com_num *com_num, double real, double imag);
t_com_num	com_multiplication(t_com_num num1, t_com_num num2);
t_com_num	com_sum(t_com_num num1, t_com_num num2);
double		com_abs_value(t_com_num num);
void		ft_mandel_iteration(t_man_dat *man_dat);
void		ft_mandel_comp(t_man_dat *man_dat);

#endif