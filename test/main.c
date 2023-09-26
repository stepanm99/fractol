#include "../incl/fractol.h"
#include<math.h>
#include<stdio.h>


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

/*Power function of complex number*/
t_com_num	ft_com_pow(t_com_num num, int pow)
{
	t_com_num	res;
	t_com_num	original;

	res = num;
	original = num;
	pow -= 1;
	while (pow > 0)
	{
		res = ft_com_multiplication(res, original);
		pow--;
	}
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

int	main()
{
	t_com_num	test1;
	t_com_num	test2;
	t_com_num	result;
	double		abs;

	abs = 0.0;
	ft_com_num_init(&test1, 1.0, 3.0);
	ft_com_num_init(&test2, 1.0, 2.0);
	ft_com_num_init(&result, 0.0, 0.0);
	printf("result: %f %fi\n", result.real, result.imag);
	printf("test1: %f %fi\n", test1.real, test1.imag);
	printf("test2: %f %fi\n", test2.real, test2.imag);

	printf("\ndivision\n");
	result = ft_com_division(test1, test2);
	printf("result: %f %fi\n", result.real, result.imag);
	printf("test1: %f %fi\n", test1.real, test1.imag);
	printf("test2: %f %fi\n", test2.real, test2.imag);

	printf("\nmultiplication\n");
	result = ft_com_multiplication(test1, test2);
	printf("result: %f %fi\n", result.real, result.imag);
	printf("test1: %f %fi\n", test1.real, test1.imag);
	printf("test2: %f %fi\n", test2.real, test2.imag);

	printf("\naddition\n");
	result = ft_com_sum(test1, test2);
	printf("result: %f %fi\n", result.real, result.imag);
	printf("test1: %f %fi\n", test1.real, test1.imag);
	printf("test2: %f %fi\n", test2.real, test2.imag);

	printf("\nsubstraction\n");
	result = ft_com_subtraction(test1, test2);
	printf("result: %f %fi\n", result.real, result.imag);
	printf("test1: %f %fi\n", test1.real, test1.imag);
	printf("test2: %f %fi\n", test2.real, test2.imag);

	printf("\npower (test1 to three)\n");
	result = ft_com_pow(test1, 3);
	printf("result: %f %fi\n", result.real, result.imag);
	printf("test1: %f %fi\n", test1.real, test1.imag);
	printf("test2: %f %fi\n", test2.real, test2.imag);

	printf("\nabsolute value (test1)\n");
	abs = ft_com_abs_value(result);
	printf("abs: %f\n", abs);
	return (0);
}
