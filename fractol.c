/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:47:44 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/07 18:48:23 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./incl/fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	ft_hook(void *param)
{
	t_man_dat	*man_dat;
	mlx_t		*mlx;

	man_dat = param;
	mlx = man_dat->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		printf("up\n");
		man_dat->y += 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		printf("down\n");
		man_dat->y -= 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		printf("left\n");
		man_dat->x += 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		printf("right\n");
		man_dat->x -= 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_PAGE_DOWN))
	{
		printf("+\n");
		man_dat->zoom += man_dat->zoom / 3;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_PAGE_UP))
	{
		printf("-\n");
		man_dat->zoom -= man_dat->zoom / 3;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_I))
	{
		man_dat->iter += 50;
		printf("iter: %i\n", man_dat->iter);
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_K))
	{
		man_dat->iter -= 50;
		printf("iter: %i\n", man_dat->iter);
		ft_mandel_comp(man_dat);
	}
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
