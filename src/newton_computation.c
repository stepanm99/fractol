/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:22:32 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/21 22:54:24 by smelicha         ###   ########.fr       */
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
{
	
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
