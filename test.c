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


/*Initialization of a compplex number*/
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
