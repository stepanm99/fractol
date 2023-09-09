/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/09 19:39:40 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void ft_put_fractal(t_dt *dt)
{
	t_man_dat	*man_dat;

	man_dat = dt->man_dat;
	if (man_dat->jul_x == 0.0 && man_dat->jul_y == 0.0)
	{
		ft_mandel_comp(man_dat);
	} else
	{
		ft_jul_comp(man_dat);
	}
}

void	ft_key_control(t_dt *dt)
{
	t_man_dat	*man_dat;
	mlx_t		*mlx;

	man_dat = dt->man_dat;
	mlx = man_dat->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		printf("up\n");
		man_dat->y += 0.1 / man_dat->zoom;
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		printf("down\n");
		man_dat->y -= 0.1 / man_dat->zoom;
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		printf("left\n");
		man_dat->x += 0.1 / man_dat->zoom;
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		printf("right\n");
		man_dat->x -= 0.1 / man_dat->zoom;
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_PAGE_DOWN))
	{
		printf("+\n");
		man_dat->zoom += man_dat->zoom / 3;
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_PAGE_UP))
	{
		printf("-\n");
		man_dat->zoom -= man_dat->zoom / 3;
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_I))
	{
		man_dat->iter += 50;
		printf("iter: %i\n", man_dat->iter);
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_K))
	{
		man_dat->iter -= 50;
		printf("iter: %i\n", man_dat->iter);
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_HOME))
	{
		man_dat->zoom = 1;
		man_dat->x = 0;
		man_dat->y = 0;
		man_dat->jul_x = 0.0;
		man_dat->jul_y = 0.0;
		printf("home\n");
		ft_put_fractal(dt);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_J))
	{
		ft_get_jul(man_dat);
		ft_put_fractal(dt);
	}
}