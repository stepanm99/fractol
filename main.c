/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/08/31 16:05:13 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"
#include <unistd.h>
#include <stdio.h>

int	main()
{
	void	*mlx_ptr;
	void	*mlx_window;


	mlx_ptr = mlx_init(640, 480, "Test", true);
	mlx_loop(mlx_ptr);
	printf("MLX pointer: %p", mlx_ptr);
	sleep(3);
	mlx_close_window(mlx_ptr);
	mlx_terminate(mlx_ptr);
}
