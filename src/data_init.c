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

/*Initialization of mandelbrot data struct*/
t_man_dat	*ft_man_dat_init(mlx_t *mlx)
{
	t_man_dat	*man_dat;

	man_dat = malloc(sizeof(t_man_dat));
	if (!man_dat)
		return (NULL);
	man_dat->mlx = mlx;
	ft_com_num_init(&man_dat->man_num.z, 0.0, 0.0);
	ft_com_num_init(&man_dat->man_num.c, 0.0, 0.0);
	man_dat->div_x = 2.47 / WIDTH;
	man_dat->div_y = 2.24 / HEIGHT;
	man_dat->x = 0.0;
	man_dat->y = 0.0;
	man_dat->zoom = 1.0;
	man_dat->x_c = 0;
	man_dat->y_c = 0;
	man_dat->iter = 250;
	man_dat->i = 0;
	return (man_dat);
}
