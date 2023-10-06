/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:53:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/06 15:06:43 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_print_help(t_dt *dt)
{
	ft_printf("How to use me\n\n");
	ft_printf("./fractol <option> :\n");
	ft_printf("\t-h\t\t\t-->prints this help\n");
	ft_printf("\tmandelbrot\t\t--> renders Mandelbrot\n");
	ft_printf("\tjulia <coor> <coor>\t--> renders Julia, coordinates\n");
	ft_printf("\t\t\t\t\toptional, recommended range (-2.0, 2.0)\n");
	ft_printf("\tnewton\t\t\t--> renders Newton fractal\n\n");
	ft_printf("key controls:\n");
	ft_printf("\tPgUp, PgDown\t--> zoom\n");
	ft_printf("\tarrows\t\t--> moving around\n");
	ft_printf("\tHome\t\t--> back to default view\n");
	ft_printf("\tEsc\t\t--> exit\n");
	ft_printf("\tI, K\t\t--> increase/decrease max. iterations\n");
	ft_printf("\tJ\t\t--> render Julia subset from a point under cursor,\n");
	ft_printf("\t\t\t\tworks for Mandelbrot\n");
	ft_printf("\tC\t\t--> changes colors, works with Mandelbrot and Julia\n");
	ft_data_free(dt);
	exit(0);
}

void	ft_print_arg_error(t_dt *dt)
{
	ft_printf("\nERROR: Unknown or no argument :(\n\n\n");
	ft_print_help(dt);
}

void	ft_print_nr_error(t_dt *dt)
{
	ft_printf("\nERROR: Wrong argument for Julia, probably not ");
	ft_printf("a floating point number? :(\n\n\n");
	ft_print_help(dt);
}

void	ft_print_too_big_arg(t_dt *dt)
{
	ft_printf("\nERROR: Number is too big or with too ");
	ft_printf("many decimal places >:(\n\n\n");
	ft_print_help(dt);
}

/*ft_error: errno
	0 -> number error (e.g.: in arg for Julia)
	1 -> wrong argument
	2 -> number too big/precise*/
void	ft_error(int errno, t_dt *dt)
{
	if (errno == 0)
		ft_print_nr_error(dt);
	if (errno == 1)
		ft_print_arg_error(dt);
	if (errno == 2)
		ft_print_too_big_arg(dt);
}
