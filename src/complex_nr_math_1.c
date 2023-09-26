/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nr_math_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:16:42 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/26 20:19:26 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Function for complex number division
	den		-> denominator
	div		-> divisor
*/
t_com_num	ft_com_division(t_com_num den, t_com_num div)
{
	t_com_num	res;
	double		real;
	double		imag;
	double		common_div;

	common_div = pow(div.real, 2.0) + pow(div.imag, 2.0);
	real = ((den.real * div.real) + (den.imag * div.imag)) / common_div;
	imag = ((den.imag * div.real) - (den.real * div.imag)) / common_div;
	ft_com_num_init(&res, real, imag);
	return (res);
}

t_com_num	ft_com_subtraction(t_com_num num1, t_com_num num2)
{
	t_com_num	res;

	res.real = num1.real - num2.real;
	res.imag = num1.imag - num2.imag;
	return (res);
}
