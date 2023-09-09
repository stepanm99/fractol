/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:47:44 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/09 16:29:55 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./incl/fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void	ft_hook(void *param)
{
	t_man_dat	*man_dat;

	man_dat = param;
	ft_key_control(man_dat);
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = ft_dt_init();
	if (!(dt->mlx = mlx_init(dt->width, dt->height, "FRACTOL", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(dt->image = mlx_new_image(dt->mlx, dt->width, dt->height)))
	{
		mlx_close_window(dt->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(dt->mlx, dt->image, 0, 0) == -1)
	{
		mlx_close_window(dt->mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_man_dat_init(dt);
	ft_mandel_comp(dt->man_dat);
	mlx_loop_hook(dt->mlx, ft_hook, dt->man_dat);
	mlx_loop(dt->mlx);
	mlx_terminate(dt->mlx);
	free(dt->man_dat);
	free(dt);
	return (EXIT_SUCCESS);
}
