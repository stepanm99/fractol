/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/18 18:15:37 by smelicha         ###   ########.fr       */
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
	printf("up\n");
	dt->man_dat->y += 0.1 / dt->man_dat->zoom;
	ft_put_fractal(dt);
}

void	ft_view_pan_down(t_dt *dt)
{
	printf("down\n");
	dt->man_dat->y -= 0.1 / dt->man_dat->zoom;
	ft_put_fractal(dt);
}

void	ft_view_pan_left(t_dt *dt)
{
	printf("left\n");
	dt->man_dat->x += 0.1 / dt->man_dat->zoom;
	ft_put_fractal(dt);
}

void	ft_view_pan_right(t_dt *dt)
{
	printf("right\n");
	dt->man_dat->x -= 0.1 / dt->man_dat->zoom;
	ft_put_fractal(dt);
}

void	ft_view_zoom_down(t_dt *dt)
{
	printf("+\n");
	dt->man_dat->zoom += dt->man_dat->zoom / 3;
	ft_put_fractal(dt);
}

void	ft_view_zoom_up(t_dt *dt)
{
	printf("-\n");
	dt->man_dat->zoom -= dt->man_dat->zoom / 3;
	ft_put_fractal(dt);
}

void	ft_view_home(t_dt *dt)
{
	dt->man_dat->zoom = 1;
	dt->man_dat->x = 0;
	dt->man_dat->y = 0;
	dt->man_dat->jul_x = 0.0;
	dt->man_dat->jul_y = 0.0;
	printf("home\n");
	ft_put_fractal(dt);
}

void	ft_view_iter_more(t_dt *dt)
{
	dt->man_dat->iter += 50;
	printf("iter: %i\n", dt->man_dat->iter);
	ft_put_fractal(dt);
}

void	ft_view_iter_less(t_dt *dt)
{
	dt->man_dat->iter -= 50;
	printf("iter: %i\n", dt->man_dat->iter);
	ft_put_fractal(dt);
}

void	ft_view_jul_from_man(t_dt *dt)
{
	ft_get_jul(dt->man_dat);
	ft_put_fractal(dt);
}

void	ft_view_change_color(t_dt *dt)
{
	ft_mandel_color_rand(dt->man_dat);
	ft_put_fractal(dt);
}

void	ft_key_control(void *param)
{
	t_man_dat	*man_dat;
	mlx_t		*mlx;
	t_dt		*dt;

	dt = param;
	man_dat = dt->man_dat;
	mlx = man_dat->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		ft_view_pan_up(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		ft_view_pan_down(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		ft_view_pan_left(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		ft_view_pan_right(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_PAGE_DOWN))
		ft_view_zoom_down(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_PAGE_UP))
		ft_view_zoom_up(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_I))
		ft_view_iter_more(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_K))
		ft_view_iter_less(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_HOME))
		ft_view_home(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_J))
		ft_view_jul_from_man(dt);
	if (mlx_is_key_down(mlx, MLX_KEY_C))
		ft_view_change_color(dt);
}
