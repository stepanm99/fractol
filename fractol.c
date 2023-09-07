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
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"


#define WIDTH 640
#define HEIGHT 480

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
	if (mlx_is_key_down(mlx, MLX_KEY_KP_ADD))
	{
		printf("+\n");
		man_dat->zoom += man_dat->zoom / 3;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_SUBTRACT))
	{
		printf("-\n");
		man_dat->zoom -= man_dat->zoom / 3;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_MULTIPLY))
	{
		man_dat->iter += 50;
		printf("iter: %i\n", man_dat->iter);
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_DIVIDE))
	{
		man_dat->iter -= 50;
		printf("iter: %i\n", man_dat->iter);
		ft_mandel_comp(man_dat);
	}
}

int	main(int argc, const char *argv[])
{
	mlx_t		*mlx;
	t_man_dat	*man_dat;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "FRACTOL", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	man_dat = ft_man_dat_init(mlx);
	ft_mandel_comp(man_dat);
	mlx_loop_hook(mlx, ft_hook, man_dat);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(man_dat);
	return (EXIT_SUCCESS);
}
