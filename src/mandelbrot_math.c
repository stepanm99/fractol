/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:45:12 by smelicha          #+#    #+#             */
/*   Updated: 2023/08/27 16:45:29 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*Initialization of a complex number*/
t_com_num	com_num_init(double real, double imag)
{
	t_com_num	res;

	res.real = real;
	res.imag = imag;
	return (res);
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

	res = (num.real * num.real) + (num.imag * num.imag);
	return (res);
}

/*One iteration of mandelbrot equation, receives pointer to a struct with
numbers for z and c for computation, directly changes z value in the struct*/
void	mandelbrot_iteration(t_man_num *m_num)
{
	t_com_num	z_pow;
	t_com_num	z_sum;

	z_pow = com_multiplication(m_num->z, m_num->z);
	z_sum = com_sum(z_pow, m_num->c);
	m_num->z = z_sum;
}
