/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_computation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:12:24 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/09 17:16:03 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Algorithm to compute Julia set; uses same functions as Mandelbrot set*/
void	ft_jul_comp(t_man_dat *man_dat)
{
	while (man_dat->y_c < man_dat->height)
	{
		while (man_dat->x_c < man_dat->width)
		{
			ft_com_num_init(&man_dat->man_num.z, man_dat->jul_x,
				man_dat->jul_y);
			ft_com_num_init(&man_dat->man_num.c,
				(((((double)man_dat->x_c * man_dat->div_x) - 2.0)
						/ man_dat->zoom) + man_dat->x),
				(((((double)man_dat->y_c
								* man_dat->div_y) - 1.12)
						/ man_dat->zoom) + man_dat->y));
			ft_mandel_iteration(man_dat);
			man_dat->i = 0;
			man_dat->x_c++;
		}
		man_dat->x_c = 0;
		man_dat->y_c++;
	}
	man_dat->x_c = 0;
	man_dat->y_c = 0;
}
