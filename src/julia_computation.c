/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_computation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:12:24 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 16:15:30 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Function to get complex plane coordinates under the cursor in Mandelbrot view
	for Julia computation*/
void	ft_get_jul(t_man_dat *man_dat)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(man_dat->mlx, &x, &y);
	if ((x <= 0 || y <= 0) || (x >= man_dat->width || y >= man_dat->height))
		return ;
	man_dat->jul_x = (((((double)x * man_dat->div_x) - 2.0)
				/ man_dat->zoom) + man_dat->x);
	man_dat->jul_y = (((((double)y * man_dat->div_y) - 1.12)
				/ man_dat->zoom) + man_dat->y);
	man_dat->zoom = 1;
}

/*Algorithm to compute Julia set; uses same functions as Mandelbrot set*/
void	ft_jul_comp(t_dt *dt)
{
	while (dt->man_dat->y_c < dt->man_dat->height)
	{
		while (dt->man_dat->x_c < dt->man_dat->width)
		{
			ft_com_num_init(&dt->man_dat->man_num.c, dt->man_dat->jul_x,
				dt->man_dat->jul_y);
			ft_com_num_init(&dt->man_dat->man_num.z,
				(((((double)dt->man_dat->x_c * dt->man_dat->div_x) - 2.0)
						/ dt->man_dat->zoom) + dt->man_dat->x),
				(((((double)dt->man_dat->y_c
								* dt->man_dat->div_y) - 1.12)
						/ dt->man_dat->zoom) + dt->man_dat->y));
			ft_mandel_iteration(dt->man_dat);
			dt->man_dat->i = 0;
			dt->man_dat->x_c++;
		}
		dt->man_dat->x_c = 0;
		dt->man_dat->y_c++;
	}
	dt->man_dat->x_c = 0;
	dt->man_dat->y_c = 0;
}
