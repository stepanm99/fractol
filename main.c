/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/07 17:32:48 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "./src/fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 640
#define HEIGHT 480

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/*
void ft_randomize(void* param)
{
	static int	x;
	static int	y;

	if (x != image->instances[0].x || y != image->instances[0].y)
	{
//		printf("x: %i, y: %i\nstruct x: %i, struct y: %i\n\n", x, y, image->instances[0].x, image->instances[0].y);
		for (int32_t i = 0; i < image->width; ++i)
		{
			for (int32_t y = 0; y < image->height; ++y)
			{
				uint32_t color = ft_pixel(
					rand() % 0xff, // R
					rand() % 0xff, // G
					i, // B
					255  // A
				);
				mlx_put_pixel(image, i, y, color);
			}
		}
	}
	x = image->instances[0].x;
	y = image->instances[0].y;
}
*/



void	ft_mandel_inside_color(t_man_dat *man_dat)
{
	mlx_put_pixel(image, man_dat->x_c, man_dat->y_c, 0x000000ff);
}

void	ft_lhc_to_rgb(t_man_dat *man_dat)
{
	
}

void	ft_mandel_outside_color(t_man_dat *man_dat)
{
	double	smooth_coef;

	smooth_coef = com_abs_value(man_dat->man_num.z) - 4.0;
	mlx_put_pixel(image, man_dat->x_c, man_dat->y_c, ((int)((man_dat->i + smooth_coef) * 8) << 24 | (int)(man_dat->i + smooth_coef) * 5 << 16 | (int)(man_dat->i + smooth_coef) * 6 << 8 | 255));
}

void	ft_mandel_iteration(t_man_dat *man_dat)
{
	t_com_num	z_pow;

	while (man_dat->i <= man_dat->iter)
	{
		if (com_abs_value(man_dat->man_num.z) > 4.0)
		{
			ft_mandel_outside_color(man_dat);
			break ;
		}
		else if (com_abs_value(man_dat->man_num.z) < 4 && man_dat->i == (man_dat->iter))
		{
			ft_mandel_inside_color(man_dat);
			break ;
		}
		z_pow = com_multiplication(man_dat->man_num.z, man_dat->man_num.z);
		man_dat->man_num.z = com_sum(z_pow, man_dat->man_num.c);
		man_dat->i++;
	}
}



/*mlx_put_pixel(image, man_dat->x_c, man_dat->y_c, ft_pixel(255, 0, 0, 255));*/
void ft_mandel_comp(t_man_dat *man_dat)
{
	while (man_dat->y_c < HEIGHT)
	{
		while (man_dat->x_c < WIDTH)
		{
			com_num_init(&man_dat->man_num.z, 0.0, 0.0);
			com_num_init(&man_dat->man_num.c, (((((double)man_dat->x_c * man_dat->div_x) - 2.0) / man_dat->zoom) + man_dat->x),
										(((((double)man_dat->y_c * man_dat->div_y) - 1.12) /man_dat->zoom) + man_dat->y));
			ft_mandel_iteration(man_dat);
			man_dat->i = 0;
			man_dat->x_c++;
		}
		man_dat->x_c = 0;
		man_dat->y_c++;
	}
	man_dat->x_c = 0;
	man_dat->y_c = 0;
}
/* old function
void ft_mandel_comp(void *param, t_man_dat *man_dat)
{
//	printf("from mandel comp\n");
	while (man_dat->y_c <= (HEIGHT - 1))
	{
		while (man_dat->x_c <= (WIDTH - 1))
		{
			com_num_init(&man_dat->man_num.z, 0.0, 0.0);
			com_num_init(&man_dat->man_num.c, ((((man_dat->x_c * man_dat->div_x) - 2.0) / man_dat->zoom) + man_dat->x),
										((((man_dat->y_c * man_dat->div_y) - 1.12) /man_dat->zoom) + man_dat->y));
			while (man_dat->i <= man_dat->iter)
			{
				if (com_abs_value(man_dat->man_num.z) > 4)
				{
					uint32_t color = ft_pixel(man_dat->i, man_dat->i, man_dat->i, 255);
					mlx_put_pixel(image, (u_int32_t)man_dat->x_c, (u_int32_t)man_dat->y_c, color);
					break ;
				}

				mandelbrot_one_iteration(man_dat);
				man_dat->i++;
			}
			if (man_dat->i == man_dat->iter)
			{
				uint32_t color = ft_pixel(0, 0, 0, 255);
				mlx_put_pixel(image, (u_int32_t)man_dat->x_c, (u_int32_t)man_dat->y_c, color);
			}
			man_dat->i = 0;
			man_dat->x_c++;
		}
		man_dat->x_c = 0;
		man_dat->y_c++;
	}
}*/

void ft_hook(void *param)
{
	t_man_dat *man_dat = param;
	mlx_t* mlx = man_dat->mlx;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		printf("up\n");
		man_dat->y += 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		printf("down\n");
		man_dat->y -= 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		printf("left\n");
		man_dat->x += 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		printf("right\n");
		man_dat->x -= 0.1 / man_dat->zoom;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_ADD))
	{
		printf("+\n");
		man_dat->zoom += man_dat->zoom / 3;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_SUBTRACT))
	{
		printf("-\n");
		man_dat->zoom -= man_dat->zoom / 3;
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_MULTIPLY))
	{
		man_dat->iter += 50;
		printf("iter: %i\n", man_dat->iter);
		ft_mandel_comp(man_dat);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_KP_DIVIDE))
	{
		man_dat->iter -= 50;
		printf("iter: %i\n", man_dat->iter);
		ft_mandel_comp(man_dat);
	}
}
/*if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;*/

/*
	t_man_num	man_num;
	double		div_x;
	double		div_y;
	int			x_c;
	int			y_c;
	int			i;

	div_x =  2.47 / WIDTH;
	div_y =  2.24 / HEIGHT;
	x_c = 0;
	y_c = 0;
	i = 0;
*/

t_man_dat	*man_dat_init(mlx_t *mlx)
{
	t_man_dat	*man_dat;

	man_dat = malloc(sizeof(t_man_dat));
	if (!man_dat)
		return (NULL);
	man_dat->mlx = mlx;
	com_num_init(&man_dat->man_num.z, 0.0, 0.0);
	com_num_init(&man_dat->man_num.c, 0.0, 0.0);
	man_dat->div_x = 2.47 / WIDTH;
	man_dat->div_y = 2.24 / HEIGHT;
	man_dat->x = 0.0;
	man_dat->y = 0.0;
	man_dat->zoom = 1.0;
	man_dat->x_c = 0;
	man_dat->y_c = 0;
	man_dat->iter = 250;
	man_dat->i = 0;
	return (man_dat);
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t		*mlx;
	t_man_dat	*man_dat;

	
	//Init error checks
//	if (!(man_dat = man_dat_init()))
//		return (EXIT_FAILURE);
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "FRACTOL", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	man_dat = man_dat_init(mlx);


	printf("iter from struct = %i\n", man_dat->iter);
//	ft_randomize(mlx);
	ft_mandel_comp(man_dat);
//	mlx_loop_hook(mlx, ft_randomize, man_dat);
	mlx_loop_hook(mlx, ft_hook, man_dat);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(man_dat);
	return (EXIT_SUCCESS);
}







/*void	ft_mandelbrot(void* param)
{
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	float	z;
	int		xcoor;
	int		ycoor;
	int		i;
	int		imax;

	xcoor = 0;
	ycoor = 0;
	imax = 250;
	x = -2.0;
	y = -1.5;
	z = 0.0;
	xinc = 4.0 / image->width;
	yinc = 3.0 / image->height;
	while (ycoor <= image->height)
	{
		while (xcoor <= image->width)
		{
			z = x;
			i = 0;
			while (i <= imax && z >= 0)
			{
				z = (z * z) + y;
				i++;
			}
			if (i == imax)
			{
				uint32_t color = ft_pixel(
					255,
					255,
					255,
					0
				);
				printf("i==imax\n");
				mlx_put_pixel(image, xcoor, ycoor, color);
			}
			else
			{
				uint32_t color = ft_pixel(
					0,
					0,
					0,
					0
				);
				printf("else\n");
				mlx_put_pixel(image, xcoor, ycoor, color);
			}
			x = x + xinc;
			xcoor++;
		}
		y = y + yinc;
		xcoor = 0;
		ycoor++;
	}
}*/



/*
#include "src/fractol.h"
#include <unistd.h>
#include <stdio.h>

int	main()
{
	mlx_t	*mlx_ptr;
	mlx_image_t	*mlx_ip;
	int		ix;
	int		iy;

	ix = 0;
	iy = 0;
	mlx_ptr = mlx_init(640, 480, "Test", true);
	mlx_ip = mlx_new_image(mlx_ptr, 640, 480);
	while (iy != 480)
	{
		printf("%i\n", iy);
		while (ix != 640)
		{
			mlx_put_pixel(mlx_ip, ix, iy, 0x00ff0000);
			ix++;
		}
		ix = 0;
		iy++;
	}
	mlx_image_to_window(mlx_ptr, mlx_ip, 640, 480);
	mlx_loop(mlx_ptr);
	printf("MLX pointer: %p", mlx_ptr);
	sleep(3);
	mlx_close_window(mlx_ptr);
	mlx_terminate(mlx_ptr);
}*/