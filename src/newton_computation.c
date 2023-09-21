/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:32 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/21 22:26:30 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

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
{/*
	while (new_dat->i <= new_dat->iter)
	{
		if (ft_com_abs_value(new_dat->man_num.z) > 2.0)
		{
			ft_mandel_outside_color(new_dat);
			break ;
		}
		else if (ft_com_abs_value(new_dat->man_num.z) < 4
			&& new_dat->i == (new_dat->iter))
		{
			ft_mandel_inside_color(new_dat);
			break ;
		}
		new_dat->z -= ft_com_division(new_dat->func_res, new_dat->deri_res);
		new_dat->i++;
	}*/
}

void	ft_new_comp(t_dt *dt)
{/*
	while (dt->new_dat->y_c < dt->new_dat->height)
	{
		while (dt->new_dat->x_c < dt->new_dat->width)
		{
			ft_com_num_init(&dt->new_dat->z,
				(((((double)new_dat->x_c * dt->new_dat->div_x) - 2.5)
						/ dt->new_dat->zoom) + dt->new_dat->x),
				(((((double)dt->new_dat->y_c
								* dt->new_dat->div_y) - 1.0)
						/ dt->new_dat->zoom) + dt->new_dat->y));
			ft_new_iteration(dt->new_dat);
			dt->new_dat->i = 0;
			dt->new_dat->x_c++;
		}
		dt->new_dat->x_c = 0;
		dt->new_dat->y_c++;
	}
	dt->new_dat->x_c = 0;
	dt->new_dat->y_c = 0;*/
}
