/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_computation_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:26:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 16:16:28 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Decides what color is the point according to which root the point converges*/
void	ft_new_color(t_new_dat	*new_dat)
{
	if (new_dat->c_i == 0)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0xff0000ff);
		return ;
	}
	if (new_dat->c_i == 1)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0x00ff00ff);
		return ;
	}
	if (new_dat->c_i == 2)
	{
		mlx_put_pixel(new_dat->image, new_dat->x_c, new_dat->y_c, 0x0000ffff);
		return ;
	}
}
