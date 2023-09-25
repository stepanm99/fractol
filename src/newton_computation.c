/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:32 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/25 20:38:55 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"
#include<stdio.h>

void	ft_new_color(t_new_dat	*new_dat)
{
//	ft_printf("from new color\n");
	if (new_dat->c_i == 0)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0xff0000ff);
//		printf("red\n");
	}
	if (new_dat->c_i == 1)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0x00ff00ff);
//		printf("green\n");
	}
	if (new_dat->c_i == 2)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0x0000ffff);
//		printf("blue\n");
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

void	ft_new_iter(t_new_dat *new_dat)
{
//	ft_printf("from ft_new_iter\n");
	double	diff;

	diff = 0.0;
	while (new_dat->i <= new_dat->iter)
	{
		ft_new_function(new_dat);
		ft_new_derivation(new_dat);
		new_dat->z = ft_com_subtraction(new_dat->z,
			ft_com_division(new_dat->func_res, new_dat->deri_res));
		while (new_dat->c_i <= 2)
		{
			diff = ft_com_abs_value(ft_com_subtraction(new_dat->z,
				new_dat->roots[new_dat->c_i]));
//			printf("diff: %f\n", diff);
//			ft_printf("c_i: %i\n", new_dat->c_i);
			if (diff <= new_dat->tolerance)
				ft_new_color(new_dat);
			new_dat->c_i++;
		}
		new_dat->c_i = 0;
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
				(((((double)dt->new_dat->x_c * dt->new_dat->div_x) - 2.5)
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
