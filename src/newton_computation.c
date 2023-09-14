/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:32 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/12 20:17:28 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_new_iter(t_new_dat *new_dat)
{
	/*
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
		z_pow = ft_com_multiplication(new_dat->man_num.z, new_dat->man_num.z);
		new_dat->man_num.z = ft_com_sum(z_pow, new_dat->man_num.c);
		new_dat->i++;
	}*/
}

void	ft_new_comp(t_new_dat *new_dat)
{



	/*
	while (new_dat->y_c < new_dat->height)
	{
		while (new_dat->x_c < new_dat->width)
		{
			ft_com_num_init(&new_dat->man_num.z,
				(((((double)new_dat->x_c * new_dat->div_x) - 2.0)
						/ new_dat->zoom) + new_dat->x),
				(((((double)new_dat->y_c
								* new_dat->div_y) - 1.12)
						/ new_dat->zoom) + new_dat->y));
			ft_new_iteration(new_dat);
			new_dat->i = 0;
			new_dat->x_c++;
		}
		new_dat->x_c = 0;
		new_dat->y_c++;
	}
	new_dat->x_c = 0;
	new_dat->y_c = 0;*/
}
