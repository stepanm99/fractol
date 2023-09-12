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
	while (man_dat->i <= man_dat->iter)
	{
		if (ft_com_abs_value(man_dat->man_num.z) > 2.0)
		{
			ft_mandel_outside_color(man_dat);
			break ;
		}
		else if (ft_com_abs_value(man_dat->man_num.z) < 4
			&& man_dat->i == (man_dat->iter))
		{
			ft_mandel_inside_color(man_dat);
			break ;
		}
		z_pow = ft_com_multiplication(man_dat->man_num.z, man_dat->man_num.z);
		man_dat->man_num.z = ft_com_sum(z_pow, man_dat->man_num.c);
		man_dat->i++;
	}
}

void	ft_new_comp(t_new_dat *new_dat)
{
	while (man_dat->y_c < man_dat->height)
	{
		while (man_dat->x_c < man_dat->width)
		{
			ft_com_num_init(&man_dat->man_num.z,
				(((((double)man_dat->x_c * man_dat->div_x) - 2.0)
						/ man_dat->zoom) + man_dat->x),
				(((((double)man_dat->y_c
								* man_dat->div_y) - 1.12)
						/ man_dat->zoom) + man_dat->y));
			ft_new_iteration(man_dat);
			man_dat->i = 0;
			man_dat->x_c++;
		}
		man_dat->x_c = 0;
		man_dat->y_c++;
	}
	man_dat->x_c = 0;
	man_dat->y_c = 0;
}
