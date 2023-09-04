/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:58:08 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/02 20:13:40 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./src/fractol.h"

int	main(void)
{
	t_man_num	man_num;
	t_man_num	*man_num_ptr;
	t_com_num	num1;
	t_com_num	num2;
	t_com_num	result;

	num1 = com_num_init(8.0, 10.0);
	num2 = com_num_init(3.0, 5.0);
	man_num_ptr = &man_num;
	man_num.z = com_num_init(0.0, 0.0);
	man_num.c = com_num_init(0.5, 0.5);
	printf("z: % f + % fi c: % f + % fi\n", man_num.z.real, man_num.z.imag, man_num.c.real, man_num.c.imag);
	mandelbrot_iteration(man_num_ptr);
	printf("z: % f + % fi c: % f + % fi\n", man_num.z.real, man_num.z.imag, man_num.c.real, man_num.c.imag);
	mandelbrot_iteration(man_num_ptr);
	printf("z: % f + % fi c: % f + % fi\n", man_num.z.real, man_num.z.imag, man_num.c.real, man_num.c.imag);
	mandelbrot_iteration(man_num_ptr);
	printf("z: % f + % fi c: % f + % fi\n", man_num.z.real, man_num.z.imag, man_num.c.real, man_num.c.imag);
	mandelbrot_iteration(man_num_ptr);
	printf("z: % f + % fi c: % f + % fi\n", man_num.z.real, man_num.z.imag, man_num.c.real, man_num.c.imag);
	result = com_multiplication(num1, num2);
	printf("result: % f + % fi\n", result.real, result.imag);
	return (0);
}
