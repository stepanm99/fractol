/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:45:53 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 17:55:19 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Function for zoom scrolling in Mandelbrot and Julia fractal*/
void	ft_scroll_man(double xdelta, double ydelta, t_dt *dt)
{
	dt->man_dat->zoom += ydelta;
}

/*Function for zoom scrolling in Newton fractal*/
void	ft_scroll_new(double xdelta, double ydelta, t_dt *dt)
{
	dt->new_dat->zoom += ydelta;
}

/*Zoom scrolling functions, gets the data about scrolling and fractal
	and decides what to do next*/
void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_dt		*dt;

	dt = param;
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		ft_scroll_man(xdelta, ydelta, dt);
	if (dt->fr_flag == 3)
		ft_scroll_new(xdelta, ydelta, dt);
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
