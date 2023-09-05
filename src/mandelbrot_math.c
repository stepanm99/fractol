/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:45:12 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/05 20:25:18 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*Initialization of a complex number*/
void	com_num_init(t_com_num *com_num, double real, double imag)
{
	com_num->real = real;
	com_num->imag = imag;
}

/*Multiplication of two comlex numbers stored as t_com_num*/
t_com_num	com_multiplication(t_com_num num1, t_com_num num2)
{
	t_com_num	res;

	res.real = ((num1.real * num2.real) - (num1.imag * num2.imag));
	res.imag = ((num1.real * num2.imag) + (num1.imag * num2.real));
	return (res);
}
/*Sum of two complex numbers stored as t_com_num*/
t_com_num	com_sum(t_com_num num1, t_com_num num2)
{
	t_com_num	res;

	res.real = num1.real + num2.real;
	res.imag = num1.imag + num2.imag;
	return (res);
}

double com_abs_value(t_com_num num)
{
	double	res;

	res = ((num.real * num.real) + (num.imag * num.imag));
//	printf("pseudoabsvalue: % f\n", res);
//	printf("num.real = % f\tnum.imag = % f", num.real, num.imag);
	return (res);
}

/*One iteration of mandelbrot equation, receives pointer to a struct with
numbers for z and c for computation, directly changes z value in the struct*/
void	mandelbrot_iteration(t_man_dat *man_dat)
{
	t_com_num	z_pow;
	t_com_num	z_sum;

	z_pow = com_multiplication(man_dat->man_num.z, man_dat->man_num.z);
	z_sum = com_sum(z_pow, man_dat->man_num.c);
	man_dat->man_num.z = z_sum;
}
