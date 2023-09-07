/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:29:45 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/07 18:39:46 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

t_dt	*ft_dt_init(void)
{
	t_dt	*dt;

	dt = malloc(sizeof(t_dt));
	if (!dt)
		return (NULL);
	dt->width = 640;
	dt->height = 480;
	return(dt);
}

/*Initialization of mandelbrot data struct*/
void	*ft_man_dat_init(t_dt *dt)
{
	t_man_dat	*man_dat;

	man_dat = malloc(sizeof(t_man_dat));
	if (!man_dat)
		return (NULL);
	man_dat->mlx = dt->mlx;
	man_dat->image = dt->image;
	man_dat->width = dt->width;
	man_dat->height = dt->height;
	ft_com_num_init(&man_dat->man_num.z, 0.0, 0.0);
	ft_com_num_init(&man_dat->man_num.c, 0.0, 0.0);
	man_dat->div_x = 2.47 / dt->width;
	man_dat->div_y = 2.24 / dt->height;
	man_dat->x = 0.0;
	man_dat->y = 0.0;
	man_dat->zoom = 1.0;
	man_dat->x_c = 0;
	man_dat->y_c = 0;
	man_dat->iter = 250;
	man_dat->i = 0;
	dt->man_dat = man_dat;
	return (man_dat);
}
