/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nr_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:59:20 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/07 18:15:57 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Initialization of a complex number*/
void	ft_com_num_init(t_com_num *com_num, double real, double imag)
{
	com_num->real = real;
	com_num->imag = imag;
}

/*Multiplication of two comlex numbers stored as t_com_num*/
t_com_num	ft_com_multiplication(t_com_num num1, t_com_num num2)
{
	t_com_num	res;

	res.real = ((num1.real * num2.real) - (num1.imag * num2.imag));
	res.imag = ((num1.real * num2.imag) + (num1.imag * num2.real));
	return (res);
}

/*Sum of two complex numbers stored as t_com_num*/
t_com_num	ft_com_sum(t_com_num num1, t_com_num num2)
{
	t_com_num	res;

	res.real = num1.real + num2.real;
	res.imag = num1.imag + num2.imag;
	return (res);
}

double	ft_com_abs_value(t_com_num num)
{
	return (sqrt((num.real * num.real) + (num.imag * num.imag)));
}
