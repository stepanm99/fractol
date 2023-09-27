/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:29:45 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/27 20:52:42 by smelicha         ###   ########.fr       */
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
	dt->fr_flag = 0;
	dt->width = 640;
	dt->height = 480;
	dt->jul_x = 0.368;
	dt->jul_y = -0.355;
	dt->man_dat = NULL;
	dt->new_dat = NULL;
	return(dt);
}

/*Decides which struct gets initialized based on the desired fractal*/
void	ft_fr_dat_init(t_dt *dt)
{
	if (dt->fr_flag == 1)
		ft_man_dat_init(dt);
	if (dt->fr_flag == 2)
		ft_man_dat_init(dt);
	if (dt->fr_flag == 3)
		ft_new_dat_init(dt);
}

/*Initializes struct for computing newton fractal*/
void	ft_new_dat_init(t_dt *dt)
{
	ft_printf("from new dat init\n");
	dt->new_dat = malloc(sizeof(t_new_dat));
	if (!dt->new_dat)
		return ;
	dt->new_dat->mlx = dt->mlx;
	dt->new_dat->image = dt->image;
	dt->new_dat->width = dt->width;
	dt->new_dat->height = dt->height;
	ft_com_num_init(&dt->new_dat->deri_res, 0.0, 0.0);
	ft_com_num_init(&dt->new_dat->func_res, 0.0, 0.0);
	ft_com_num_init(&dt->new_dat->three, 3.0, 0.0);
	ft_com_num_init(&dt->new_dat->z, 0.0, 0.0);
	ft_com_num_init(&dt->new_dat->roots[0], 1.0, 0.0);
	ft_com_num_init(&dt->new_dat->roots[1], -0.5, (sqrt(3.0) / 2.0));
	ft_com_num_init(&dt->new_dat->roots[2], -0.5, -(sqrt(3.0) / 2.0));
	dt->new_dat->tolerance = 0.000001;
	dt->new_dat->iter = 50;
	dt->new_dat->i = 0;
	dt->new_dat->c_i = 0;
	dt->new_dat->div_x = 2.0 / dt->width;
	dt->new_dat->div_y = 2.0 / dt->height;
	dt->new_dat->x_c = 0;
	dt->new_dat->y_c = 0;
	dt->new_dat->x = 0.0;
	dt->new_dat->y = 0.0;
	dt->new_dat->zoom = 1.0;
}

/*Checks if the desired fractal is Julia, if user gives coordinates when
starting the program it saves them to the struct*/
void	ft_jul_init_check(t_dt *dt)
{
	if (dt->fr_flag == 2)
	{
		dt->man_dat->jul_x = dt->jul_x;
		dt->man_dat->jul_y = dt->jul_y;
	}
}

/*Initialization of mandelbrot data struct*/
void	ft_man_dat_init(t_dt *dt)
{
	dt->man_dat = malloc(sizeof(t_man_dat));
	if (!dt->man_dat)
		return ;
	dt->man_dat->mlx = dt->mlx;
	dt->man_dat->image = dt->image;
	dt->man_dat->width = dt->width;
	dt->man_dat->height = dt->height;
	ft_com_num_init(&dt->man_dat->man_num.z, 0.0, 0.0);
	ft_com_num_init(&dt->man_dat->man_num.c, 0.0, 0.0);
	dt->man_dat->div_x = 2.47 / dt->width;
	dt->man_dat->div_y = 2.24 / dt->height;
	dt->man_dat->jul_x = 0.0;
	dt->man_dat->jul_y = 0.0;
	dt->man_dat->x = 0.0;
	dt->man_dat->y = 0.0;
	dt->man_dat->zoom = 1.0;
	dt->man_dat->x_c = 0;
	dt->man_dat->y_c = 0;
	dt->man_dat->iter = 250;
	dt->man_dat->i = 0;
	dt->man_dat->man_col.r_coef = 8;
	dt->man_dat->man_col.g_coef = 5;
	dt->man_dat->man_col.b_coef = 6;
	ft_jul_init_check(dt);
	ft_put_fractal(dt);
}
