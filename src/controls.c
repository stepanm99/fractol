/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 16:13:41 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

/*Decides which fractal to compute according to dt->fr_flag*/
void	ft_put_fractal(t_dt *dt)
{
	if (dt->fr_flag == 1)
		ft_mandel_comp(dt);
	if (dt->fr_flag == 2)
		ft_jul_comp(dt);
	if (dt->fr_flag == 3)
		ft_new_comp(dt);
}

void	ft_key_control_1(t_dt *dt)
{
	if (mlx_is_key_down(dt->mlx, MLX_KEY_J))
		ft_view_jul_from_man(dt);
	if (mlx_is_key_down(dt->mlx, MLX_KEY_C))
		ft_view_change_color(dt);
}

/*Decides what to do when certain key is pressed*/
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
