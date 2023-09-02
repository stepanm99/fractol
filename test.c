/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:58:08 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/02 15:42:34 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef struct com_num
{
	double	real;
	double	imaginary;
}	com_num_t;

typedef struct man_num
{
	com_num_t	z;
	com_num_t	c;
} man_num_t;

com_num_t	com_num_init(double real, double imaginary)
{
	com_num_t	result;

	result.real = real;
	result.imaginary = imaginary;
	return(result);
}

com_num_t	com_multiplication(com_num_t num1, com_num_t num2)
{
	com_num_t	result;

	result.real = ((num1.real * num2.real) - (num1.imaginary * num2.imaginary));
	result.imaginary = ((num1.real * num2.imaginary) + (num1.imaginary * num2.real));

	return(result);
}

int	check_man_set_belonging(man_num_t *mandelbrot_num)
{
	int	max_i = 200;
	mandelbrot_num->z.real = 0;
	mandelbrot_num->z.imaginary = 0;

	printf("manndelbrot c real: %f", mandelbrot_num->c.real);
	return(0);
}

int	main(void) 
{
	man_num_t	mandelbrot_num;
	man_num_t	*man_num_ptr;

	man_num_ptr = &mandelbrot_num;
	mandelbrot_num.c.real = 0.5;
	mandelbrot_num.c.imaginary = 0.5;
	mandelbrot_num.z = com_num_init(0.0, 0.0);
	mandelbrot_num.c = com_num_init(0.5, 0.5);

	mandelbrot_num.z = com_multiplication(mandelbrot_num.z, mandelbrot_num.c);
	mandelbrot_num.z = com_multiplication(mandelbrot_num.z, mandelbrot_num.c);
	mandelbrot_num.z = com_multiplication(mandelbrot_num.z, mandelbrot_num.c);
	printf("z: %f + %fi c: %f + %fi", mandelbrot_num.z.real, mandelbrot_num.z.imaginary, mandelbrot_num.c.real, mandelbrot_num.c.imaginary);
//	check_man_set_belonging(man_num_ptr);
	return(0);
}
