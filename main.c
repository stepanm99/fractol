/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:06:41 by smelicha          #+#    #+#             */
/*   Updated: 2023/08/31 15:10:58 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fractol.h"
#include <unistd.h>

int	main()
{
	void	*mlx_ptr = mlx_init(640, 480, "Test", false);

	sleep(3);
	mlx_terminate(mlx_ptr);
}
