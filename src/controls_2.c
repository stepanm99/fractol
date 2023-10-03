/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:44:31 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/03 12:13:15 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Moves the view of the fractal up*/
void	ft_view_pan_up(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		dt->man_dat->y += 0.1 / dt->man_dat->zoom;
	if (dt->fr_flag == 3)
		dt->new_dat->y += 0.1 / dt->new_dat->zoom;
	ft_put_fractal(dt);
}

/*Moves the view of the fractal down*/
void	ft_view_pan_down(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		dt->man_dat->y -= 0.1 / dt->man_dat->zoom;
	if (dt->fr_flag == 3)
		dt->new_dat->y -= 0.1 / dt->new_dat->zoom;
	ft_put_fractal(dt);
}

/*Moves the view of the fractal left*/
void	ft_view_pan_left(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		dt->man_dat->x += 0.1 / dt->man_dat->zoom;
	if (dt->fr_flag == 3)
		dt->new_dat->x += 0.1 / dt->new_dat->zoom;
	ft_put_fractal(dt);
}

/*Moves the view of the fractal right*/
void	ft_view_pan_right(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		dt->man_dat->x -= 0.1 / dt->man_dat->zoom;
	if (dt->fr_flag == 3)
		dt->new_dat->x -= 0.1 / dt->new_dat->zoom;
	ft_put_fractal(dt);
}
