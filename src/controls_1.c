/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:36:48 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/03 12:12:17 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Sets the view back to default*/
void	ft_view_home(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->fr_flag = 1;
		dt->man_dat->zoom = 1.0;
		dt->man_dat->x = 0.0;
		dt->man_dat->y = 0.0;
		dt->man_dat->jul_x = 0.0;
		dt->man_dat->jul_y = 0.0;
	}
	if (dt->fr_flag == 3)
	{
		dt->new_dat->zoom = 1;
		dt->new_dat->x = 0;
		dt->new_dat->y = 0;
	}
	ft_put_fractal(dt);
}

/*Adds more iterations for computing the fractal*/
void	ft_view_iter_more(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->man_dat->iter += 50;
		ft_printf("iter: %i\n", dt->man_dat->iter);
	}
	if (dt->fr_flag == 3)
	{
		dt->new_dat->iter += 50;
		ft_printf("iter: %i\n", dt->new_dat->iter);
	}
	ft_put_fractal(dt);
}

/*Decreases number of iterations for computing the fractal*/
void	ft_view_iter_less(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->man_dat->iter -= 50;
		ft_printf("iter: %i\n", dt->man_dat->iter);
	}
	if (dt->fr_flag == 3)
	{
		dt->new_dat->iter -= 50;
		ft_printf("iter: %i\n", dt->new_dat->iter);
	}
	ft_put_fractal(dt);
}

/*Switches to Julia fractal based on cursor coordinates
on the Mandelbrot fractal*/
void	ft_view_jul_from_man(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		dt->fr_flag = 2;
		ft_get_jul(dt->man_dat);
	}
	if (dt->fr_flag == 3)
		return ;
	ft_put_fractal(dt);
}

/*Changes the constants for color computation (for Julia and Mandelbrot)*/
void	ft_view_change_color(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		ft_mandel_color_rand(dt->man_dat);
	if (dt->fr_flag == 3)
		return ;
	ft_put_fractal(dt);
}
