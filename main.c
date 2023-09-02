/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/02 14:31:40 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./MLX42/include/MLX42/MLX42.h"

#define WIDTH 640
#define HEIGHT 480

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	static int	x;
	static int	y;

	if (x != image->instances[0].x || y != image->instances[0].y)
	{
		printf("x: %i, y: %i\nstruct x: %i, struct y: %i\n\n", x, y, image->instances[0].x, image->instances[0].y);
		for (int32_t i = 0; i < image->width; ++i)
		{
			for (int32_t y = 0; y < image->height; ++y)
			{
				uint32_t color = ft_pixel(
					rand() % 0xff, // R
					rand() % 0xff, // G
					i, // B
					y  // A
				);
				mlx_put_pixel(image, i, y, color);
			}
		}
	}
	x = image->instances[0].x;
	y = image->instances[0].y;
}

void	ft_mandelbrot(void* param)
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
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 255, 255)))
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
	
//	ft_randomize(mlx);
//	ft_mandelbrot(mlx);
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}






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
