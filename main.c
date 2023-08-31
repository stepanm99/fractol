/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/08/31 16:28:44 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"
#include <unistd.h>
#include <stdio.h>

int	main()
{
	void	*mlx_ptr;
	void	*mlx_ip;
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
	mlx_put_pixel(mlx_ip, 320, 240, 0x00ff0000);
	mlx_image_to_window(mlx_ptr, mlx_ip, 640, 480);
	mlx_loop(mlx_ptr);
	printf("MLX pointer: %p", mlx_ptr);
	sleep(3);
	mlx_close_window(mlx_ptr);
	mlx_terminate(mlx_ptr);
}
