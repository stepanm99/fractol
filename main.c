/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/08/27 16:15:51 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/minilibx/mlx.h"

int	main()
{
	void	*mlx_ptr = mlx_init();

	void	*window = mlx_new_window(mlx_ptr, 640, 480, "Test");
	getchar();
	mlx_destroy_window(mlx_ptr, window);
}