/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:45:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 15:47:13 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_scroll_man(double xdelta, double ydelta, t_dt *dt)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(dt->mlx, &x, &y);
	dt->man_dat->zoom += ydelta;
	if (ydelta > 0)
	{
	dt->man_dat->x *= (double)x / ((double)dt->man_dat->width / 2);
	dt->man_dat->y *= (double)y / ((double)dt->man_dat->height / 2);
	}
	else
	{
	dt->man_dat->x /= (double)x / ((double)dt->man_dat->width / 2);
	dt->man_dat->y /= (double)y / ((double)dt->man_dat->height / 2);
	}
}

void	ft_scroll_new(double xdelta, double ydelta, t_dt *dt)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(dt->mlx, &x, &y);
	dt->new_dat->zoom += ydelta;
	if (ydelta > 0)
	{
	dt->new_dat->x *= (double)x / ((double)dt->new_dat->width / 2);
	dt->new_dat->y *= (double)y / ((double)dt->new_dat->height / 2);
	}
	else
	{
	dt->new_dat->x -= ((((double)x * dt->new_dat->div_x) - 2.0)
				/ dt->new_dat->zoom);
	dt->new_dat->y -= ((((double)y * dt->new_dat->div_y) - 1.12)
				/ dt->new_dat->zoom);
	}
}

/*Still not very functional scroll whell zooming function for mandelbrot*/
void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_dt		*dt;

	dt = param;
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		ft_scroll_man(xdelta, ydelta, dt);
	if (dt->fr_flag == 3)
		ft_scroll(xdelta, ydelta, dt);
	ft_put_fractal(dt);
}

/*Zooms the fractal*/
void	ft_view_zoom_down(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("+\n");
		dt->man_dat->zoom += dt->man_dat->zoom / 3;
	}
	if (dt->fr_flag == 3)
	{
		ft_printf("+\n");
		dt->new_dat->zoom += dt->new_dat->zoom / 3;
	}
	ft_put_fractal(dt);
}

/*Unzooms the fractal*/
void	ft_view_zoom_up(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("-\n");
		dt->man_dat->zoom -= dt->man_dat->zoom / 3;
	}
	if (dt->fr_flag == 3)
	{
		ft_printf("-\n");
		dt->new_dat->zoom -= dt->new_dat->zoom / 3;
	}
	ft_put_fractal(dt);
}
