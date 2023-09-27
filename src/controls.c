/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:29:39 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/27 19:31:23 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"


/*Decides which fractal to compute according to the user input*/
void ft_put_fractal(t_dt *dt)
{
	if (dt->fr_flag == 1)
		ft_mandel_comp(dt);
	if (dt->fr_flag == 2)
		ft_jul_comp(dt);
	if (dt->fr_flag == 3)
		ft_new_comp(dt);
}

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
	} else
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
	} else
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

/*Moves the view of the fractal up*/
void	ft_view_pan_up(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("up\n");
		dt->man_dat->y += 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
	{
		ft_printf("up\n");
		dt->new_dat->y += 0.1 / dt->new_dat->zoom;
	}
	ft_put_fractal(dt);
}

/*Moves the view of the fractal down*/
void	ft_view_pan_down(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("down\n");
		dt->man_dat->y -= 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
	{
		ft_printf("down\n");
		dt->new_dat->y -= 0.1 / dt->new_dat->zoom;
	}
	ft_put_fractal(dt);
}

/*Moves the view of the fractal left*/
void	ft_view_pan_left(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("left\n");
		dt->man_dat->x += 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
	{
		ft_printf("left\n");
		dt->new_dat->x += 0.1 / dt->new_dat->zoom;
	}
	ft_put_fractal(dt);
}

/*Moves the view of the fractal right*/
void	ft_view_pan_right(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
	{
		ft_printf("right\n");
		dt->man_dat->x -= 0.1 / dt->man_dat->zoom;
	}
	if (dt->fr_flag == 3)
	{
		ft_printf("right\n");
		dt->new_dat->x -= 0.1 / dt->new_dat->zoom;
	}
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
		ft_printf("home\n");
	}
	if (dt->fr_flag == 3)
	{
		dt->new_dat->zoom = 1;
		dt->new_dat->x = 0;
		dt->new_dat->y = 0;
		ft_printf("home\n");
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

/*Changes the constants for color computation*/
void	ft_view_change_color(t_dt *dt)
{
	if (dt->fr_flag == 1 || dt->fr_flag == 2)
		ft_mandel_color_rand(dt->man_dat);
	if (dt->fr_flag == 3)
		return ;
	ft_put_fractal(dt);
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
