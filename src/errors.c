/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:53:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/27 20:10:05 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_print_help(t_dt *dt)
{
	ft_printf("How to use me\n\n");
	ft_printf("./fractol <option> :\n");
	ft_printf("    -h ->prints this help\n");
	ft_printf("    <nothing> && mandelbrot -> renders Mandelbrot\n");
	ft_printf("    julia <coor> <coor> -> renders Julia, coordinates\n");
	ft_printf("        optional, recommended range (-2.0, 2.0)\n");
	ft_printf("    newton -> renders Newton fractal");
	ft_printf("key controls:\n");
	ft_printf("    PgUp, PgDown -> zoom\n");
	ft_printf("    arrows -> moving around\n");
	ft_printf("    Home -> back to default view\n");
	ft_printf("    Esc -> exit\n");
	ft_printf("    I, K -> increase/decrease max. iterations\n");
	ft_printf("    J -> renders Julia subset from the point under cursor,\n");
	ft_printf("        works for Mandelbrot\n");
	ft_printf("    C -> changes colors, works with Mandelbrot and Julia\n");
	ft_data_free(dt);
	exit(0);
}

void	ft_print_arg_error(t_dt *dt)
{
	ft_printf("\nERROR: Unknown argument :/\n\n\n");
	ft_print_help(dt);
}

void	ft_print_nr_error(t_dt *dt)
{
	ft_printf("\nERROR: Wrong argument for Julia :(\n\n\n");
	ft_print_help(dt);
}

/*Decides what error should be displayed, frees allocated memory
of respective fractal*/
void	ft_error(int errno, t_dt *dt)
{
	if (errno == 0)
		ft_print_nr_error(dt);
	if (errno == 1)
		ft_print_arg_error(dt);
}
