/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:53:33 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/18 20:45:04 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	ft_print_help(void)
{
	printf("Help message :)\n");
}

void	ft_print_nr_error(void)
{
	printf("Seems like you made a typo in a number :(\n");
	ft_print_help();
}

void	ft_error(int errno)
{
	if (errno == 0)
		ft_print_nr_error();
	exit(0);
}
