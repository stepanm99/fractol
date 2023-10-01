/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:32 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 16:18:18 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Base polynomial function to compute newton fractal*/
void	ft_new_function(t_new_dat *new_dat)
{
	new_dat->func_res = ft_com_pow(new_dat->z, 3);
	new_dat->func_res.real -= 1;
}

/*Derivation of the base function*/
void	ft_new_derivation(t_new_dat *new_dat)
{
	new_dat->deri_res = ft_com_pow(new_dat->z, 2);
	new_dat->deri_res = ft_com_multiplication(new_dat->deri_res,
			new_dat->three);
}

/*Checks to which root the computed point is converging*/
void	ft_new_check_roots(t_new_dat *new_dat)
{
	double	xdiff;
	double	ydiff;

	xdiff = 0.0;
	ydiff = 0.0;
	while (new_dat->c_i <= 3)
	{
		xdiff = (new_dat->z.real - new_dat->roots[new_dat->c_i].real);
		ydiff = (new_dat->z.imag - new_dat->roots[new_dat->c_i].imag);
		if ((fabs(xdiff) <= new_dat->tolerance)
			&& (fabs(ydiff) <= new_dat->tolerance))
			ft_new_color(new_dat);
		new_dat->c_i++;
	}
	new_dat->c_i = 0;
}

/*One iteration of Newton fractal computation*/
void	ft_new_iter(t_new_dat *new_dat)
{
	while (new_dat->i <= new_dat->iter)
	{
		ft_new_function(new_dat);
		ft_new_derivation(new_dat);
		new_dat->z = ft_com_subtraction(new_dat->z,
				ft_com_division(new_dat->func_res, new_dat->deri_res));
		ft_new_check_roots(new_dat);
		new_dat->i++;
	}
}

/*Algorithm for Newton fractal computation*/
void	ft_new_comp(t_dt *dt)
{
	while (dt->new_dat->y_c < dt->new_dat->height)
	{
		while (dt->new_dat->x_c < dt->new_dat->width)
		{
			ft_com_num_init(&dt->new_dat->z,
				(((((double)dt->new_dat->x_c * dt->new_dat->div_x) - 1.0)
						/ dt->new_dat->zoom) + dt->new_dat->x),
				(((((double)dt->new_dat->y_c
								* dt->new_dat->div_y) - 1.0)
						/ dt->new_dat->zoom) + dt->new_dat->y));
			ft_new_iter(dt->new_dat);
			dt->new_dat->i = 0;
			dt->new_dat->x_c++;
		}
		dt->new_dat->x_c = 0;
		dt->new_dat->y_c++;
	}
	dt->new_dat->x_c = 0;
	dt->new_dat->y_c = 0;
}
