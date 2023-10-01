/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:47:44 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/01 20:50:40 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/fractol.h"

/*Parses the argument given to the program*/
static void	ft_arg_resolve(t_dt *dt, int argc, const char *argv[])
{
	ft_printf("argc: %i\n", argc);
	if (argc <= 1)
		dt->fr_flag = 1 ;
	else if (ft_match(argv[1], "mandelbrot"))
		dt->fr_flag = 1;
	else if (ft_match(argv[1], "julia"))
	{
		dt->fr_flag = 2;
		if (argv[2] && !argv[3])
			ft_error(0, dt);
		if (argv[2] && argv[3])
		{
			ft_printf("from ifargv\n");
			dt->jul_x = ft_atof(argv[2], dt);
			dt->jul_y = ft_atof(argv[3], dt);
		}
	}
	else if (ft_match(argv[1], "newton"))
	{
		dt->fr_flag = 3;
	}
	else if (ft_match(argv[1], "-h"))
		ft_print_help(dt);
}

/*Frees all allocated memory*/
void	ft_data_free(t_dt *dt)
{
	if (dt->man_dat)
		free(dt->man_dat);
	if (dt->new_dat)
		free(dt->new_dat);
//	if (dt->mlx)
//	{
//		mlx_close_window(dt->mlx);
//		mlx_terminate(dt->mlx);
//	}
	free(dt);
}

static int	main_1(t_dt *dt)
{
	int32_t	mlx_img_t_window;

	mlx_img_t_window = mlx_image_to_window(dt->mlx, dt->image, 0, 0);
	if (mlx_img_t_window == -1)
	{
		mlx_close_window(dt->mlx);
		ft_printf(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_fr_dat_init(dt);
	ft_put_fractal(dt);
	mlx_loop_hook(dt->mlx, ft_key_control, dt);
	mlx_scroll_hook(dt->mlx, ft_scroll, dt);
	mlx_loop(dt->mlx);
	ft_data_free(dt);
	return (EXIT_SUCCESS);
}

int	main(int argc, const char *argv[])
{
	t_dt	*dt;

	dt = ft_dt_init();
	ft_arg_resolve(dt, argc, argv);
	dt->mlx = mlx_init(dt->width, dt->height, "FRACTOL", false);
	if (!dt->mlx)
	{
		ft_printf(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	dt->image = mlx_new_image(dt->mlx, dt->width, dt->height);
	if (!dt->image)
	{
		mlx_close_window(dt->mlx);
		ft_printf(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	return (main_1(dt));
}
