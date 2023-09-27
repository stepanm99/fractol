/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:32 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/27 16:17:29 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include<stdio.h>

void	ft_new_color(t_new_dat	*new_dat)
{
//	printf("c_i: %i\n", new_dat->c_i);
//	ft_printf("from new color\n");
	if (new_dat->c_i == 0)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0xff0000ff);
//		printf("red: %i %i\n", new_dat->x_c, new_dat->y_c);
		return ;
	}
	if (new_dat->c_i == 1)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0x00ff00ff);
//		printf("green: %i %i\n", new_dat->x_c, new_dat->y_c);
		return ;
	}
	if (new_dat->c_i == 2)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0x0000ffff);
//		printf("blue: %i %i\n", new_dat->x_c, new_dat->y_c);
		return ;
	}
}

void	ft_new_function(t_new_dat *new_dat)
{
	new_dat->func_res = ft_com_pow(new_dat->z, 3);
	new_dat->func_res.real -= 1;
}

void	ft_new_derivation(t_new_dat *new_dat)
{
	new_dat->deri_res = ft_com_pow(new_dat->z, 2);
	new_dat->deri_res = ft_com_multiplication(new_dat->deri_res,
		new_dat->three);
}

void	ft_new_check_roots(t_new_dat *new_dat)
{
	double	xdiff;
	double	ydiff;

	xdiff = 0.0;
	ydiff = 0.0;
	while (new_dat->c_i <= 2)
	{
		xdiff = (new_dat->z.real - new_dat->roots[new_dat->c_i].real);
		ydiff = (new_dat->z.imag - new_dat->roots[new_dat->c_i].imag);
//		printf("xdiff: %f\nydiff: %f\n", xdiff, ydiff);
//		printf("root%i: %f %fi\n", new_dat->c_i, new_dat->roots[new_dat->c_i].real, new_dat->roots[new_dat->c_i].imag);
		if ((xdiff <= new_dat->tolerance) && (ydiff <= new_dat->tolerance))
		{
			ft_new_color(new_dat);
			return ;
		}
		new_dat->c_i++;
	}
	new_dat->c_i = 0;
}

void	ft_new_iter(t_new_dat *new_dat)
{
//	ft_printf("from ft_new_iter\n");
	while (new_dat->i <= new_dat->iter)
	{
		ft_new_function(new_dat);
		ft_new_derivation(new_dat);
		new_dat->z = ft_com_subtraction(new_dat->z,
			ft_com_division(new_dat->func_res, new_dat->deri_res));
//		printf("z: %f %fi\n", new_dat->z.real, new_dat->z.imag);
		ft_new_check_roots(new_dat);
		new_dat->i++;
	}
}

void	ft_new_comp(t_dt *dt)
{
	ft_printf("from ft_new_comp\n");
	while (dt->new_dat->y_c < dt->new_dat->height)
	{
		while (dt->new_dat->x_c < dt->new_dat->width)
		{
			ft_com_num_init(&dt->new_dat->z,
				(((((double)dt->new_dat->x_c * dt->new_dat->div_x) - 5.0)
						/ dt->new_dat->zoom) + dt->new_dat->x),
				(((((double)dt->new_dat->y_c
								* dt->new_dat->div_y) - 5.0)
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
