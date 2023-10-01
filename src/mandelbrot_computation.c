/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_computation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:59:56 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 15:24:55 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Changes coloring of the fractal*/
void	ft_mandel_color_rand(t_man_dat *man_dat)
{
	man_dat->man_col.r_coef += 3;
	if (man_dat->man_col.r_coef > 8)
		man_dat->man_col.r_coef -= 8;
	man_dat->man_col.g_coef += 1;
	if (man_dat->man_col.g_coef > 8)
		man_dat->man_col.g_coef -= 8;
	man_dat->man_col.b_coef += 2;
	if (man_dat->man_col.b_coef > 8)
		man_dat->man_col.b_coef -= 8;
}

/*If flag for coloring points belonging to the Mandebrot set is on
	this function computes the colors, otherwise it defaults black*/
void	ft_mandel_inside_color(t_man_dat *man_dat)
{
	mlx_put_pixel(man_dat->image, man_dat->x_c, man_dat->y_c, 0x000000ff);
}

/*Computes color for points outside of the mandelbrot set*/
void	ft_mandel_outside_color(t_man_dat *man_dat)
{
	double	smooth_coef;

	smooth_coef = (ft_com_abs_value(man_dat->man_num.z) - 2.0) * 7;
	mlx_put_pixel(man_dat->image, man_dat->x_c, man_dat->y_c,
		((int)((man_dat->i + smooth_coef) * man_dat->man_col.r_coef) << 24
			| (int)(man_dat->i + smooth_coef) * man_dat->man_col.g_coef << 16
			| (int)(man_dat->i + smooth_coef)
			* man_dat->man_col.b_coef << 8 | 255));
}

/*Algorithm for iterative computation, and decision whether it belongs into
	the set, of one point*/
void	ft_mandel_iteration(t_man_dat *man_dat)
{
	t_com_num	z_pow;

	while (man_dat->i <= man_dat->iter)
	{
		if (ft_com_abs_value(man_dat->man_num.z) > 2.0)
		{
			ft_mandel_outside_color(man_dat);
			break ;
		}
		else if (ft_com_abs_value(man_dat->man_num.z) < 4
			&& man_dat->i == (man_dat->iter))
		{
			ft_mandel_inside_color(man_dat);
			break ;
		}
		z_pow = ft_com_pow(man_dat->man_num.z, 2);
		man_dat->man_num.z = ft_com_sum(z_pow, man_dat->man_num.c);
		man_dat->i++;
	}
}

/*Algorithm to compute all points of the image*/
void	ft_mandel_comp(t_dt *dt)
{
	while (dt->man_dat->y_c < dt->man_dat->height)
	{
		while (dt->man_dat->x_c < dt->man_dat->width)
		{
			ft_com_num_init(&dt->man_dat->man_num.z, 0.0, 0.0);
			ft_com_num_init(&dt->man_dat->man_num.c,
				(((((double)dt->man_dat->x_c * dt->man_dat->div_x) - 2.0)
						/ dt->man_dat->zoom) + dt->man_dat->x),
				(((((double)dt->man_dat->y_c
								* dt->man_dat->div_y) - 1.12)
						/ dt->man_dat->zoom) + dt->man_dat->y));
			ft_mandel_iteration(dt->man_dat);
			dt->man_dat->i = 0;
			dt->man_dat->x_c++;
		}
		dt->man_dat->x_c = 0;
		dt->man_dat->y_c++;
	}
	dt->man_dat->x_c = 0;
	dt->man_dat->y_c = 0;
}
