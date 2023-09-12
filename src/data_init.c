/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:29:45 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/12 20:32:32 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Initialization of main data struct*/
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
/*Helper function 1 for main init function*/
void	ft_man_dat_init_1(t_man_dat *man_dat)
{
	man_dat->man_col.r_coef = 8;
	man_dat->man_col.g_coef = 5;
	man_dat->man_col.b_coef = 6;
}

void	*ft_new_dat_init(t_dt *dt)
{
	t_new_dat	*new_dat;

	new_dat = malloc(sizeof(t_new_dat));
	if (!new_dat)
		return (NULL);
	new_dat->mlx = dt->mlx;
	new_dat->image = dt->image;
	new_dat->width = dt->width;
	new_dat->height = dt->height;
	ft_com_num_init(&new_dat->z, 0.0, 0.0);
	ft_com_num_init(&new_dat->func_res, 0.0, 0.0);
	ft_com_num_init(&new_dat->deri_res, 0.0, 0.0);
	new_dat->tolerance = 0.000001;
	new_dat->iter = 50;
	new_dat->i = 0;
	new_dat->x_div = 2.47 / dt->width;
	new_dat->y_div = 2.24 / dt->height;
	new_dat->x = 0.0;
	new_dat->y = 0.0;
	new_dat->zoom = 1.0;
	return (new_dat);
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
	man_dat->jul_x = 0.0;
	man_dat->jul_y = 0.0;
	man_dat->x = 0.0;
	man_dat->y = 0.0;
	man_dat->zoom = 1.0;
	man_dat->x_c = 0;
	man_dat->y_c = 0;
	man_dat->iter = 250;
	man_dat->i = 0;
	dt->man_dat = man_dat;
	ft_man_dat_init_1(man_dat);
	return (man_dat);
}
