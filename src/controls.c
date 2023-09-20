/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/20 15:57:42 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void ft_put_fractal(t_dt *dt)
{
	if (dt->fr_flag == 1)
		ft_mandel_comp(dt);
	if (dt->fr_flag == 2)
		ft_jul_comp(dt);
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_dt		*dt;
	t_man_dat	*man_dat;
	int			x;
	int			y;

	dt = param;
	man_dat = dt->man_dat;
	mlx_get_mouse_pos(dt->mlx, &x, &y);
	dt->man_dat->zoom += ydelta;
	if (ydelta > 0)
	{
	dt->man_dat->x *= (double)x / ((double)man_dat->width / 2);
	dt->man_dat->y *= (double)y / ((double)man_dat->height / 2);
	} else
	{
	dt->man_dat->x -= ((((double)x * man_dat->div_x) - 2.0)
						/ man_dat->zoom);
	dt->man_dat->y -= ((((double)y * man_dat->div_y) - 1.12)
						/ man_dat->zoom);
	}
	ft_put_fractal(dt);
}
void	ft_view_pan_up(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("up\n");
		dt->man_dat->y += 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_pan_down(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("down\n");
		dt->man_dat->y -= 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_pan_left(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("left\n");
		dt->man_dat->x += 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_pan_right(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("right\n");
		dt->man_dat->x -= 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_zoom_down(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("+\n");
		dt->man_dat->zoom += dt->man_dat->zoom / 3;
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_zoom_up(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("-\n");
		dt->man_dat->zoom -= dt->man_dat->zoom / 3;
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_home(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->fr_flag = 1;
		dt->man_dat->zoom = 1;
		dt->man_dat->x = 0;
		dt->man_dat->y = 0;
		dt->man_dat->jul_x = 0.0;
		dt->man_dat->jul_y = 0.0;
		ft_printf("home\n");
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_iter_more(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->man_dat->iter += 50;
		ft_printf("iter: %i\n", dt->man_dat->iter);
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_iter_less(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->man_dat->iter -= 50;
		ft_printf("iter: %i\n", dt->man_dat->iter);
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_jul_from_man(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->fr_flag = 2;
		ft_get_jul(dt->man_dat);
	}
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_view_change_color(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		ft_mandel_color_rand(dt->man_dat);
	if (dt->fr_flag == 3)
		ft_printf("Newton key control prototype\n");
	ft_put_fractal(dt);
}

void	ft_key_control_1(t_dt *dt)
{
	if (mlx_is_key_down(dt->mlx, MLX_KEY_J))
		ft_view_jul_from_man(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_C))
		ft_view_change_color(dt);
}

void	ft_key_control(void *param)
{
	t_dt		*dt;

	dt = param;
	if (mlx_is_key_down(dt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(dt->mlx);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_UP))
		ft_view_pan_up(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_DOWN))
		ft_view_pan_down(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_LEFT))
		ft_view_pan_left(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_RIGHT))
		ft_view_pan_right(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_PAGE_DOWN))
		ft_view_zoom_down(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_PAGE_UP))
		ft_view_zoom_up(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_I))
		ft_view_iter_more(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_K))
		ft_view_iter_less(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_HOME))
		ft_view_home(dt);
	ft_key_control_1(dt);
}
