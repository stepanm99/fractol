/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:20:07 by smelicha          #+#    #+#             */
/*   Updated: 2023/09/14 22:24:10 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

double	ft_atof_before_point(const char *str, int *i)
{
	double	n;

	n = 0.0;
	while ((str[*i] >= '0' && str[*i] <= '9') && (str[*i] != '.' || str[*i]) != '\0')
	{
		n = n * 10 + (str[*i] - '0');
		*i += 1;
	}
	return (n);
}

double	ft_atoi_after_point(const char *str, int *i)
{
	double	n;
	int		j;

	n = 0.0;
	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		n = n * 10 + (str[*i] - '0');
		*i += 1;
		j++;
	}
	while (j != 0)
	{
		n = n / 10;
		j--;
	}
	return (n);
}

double	ft_atof(const char *str)
{
	int		i;
	int		negflag;
	double	n;

	i = 0;
	n = 0;
	negflag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			negflag = (-1);
		i++;
	}
	n += ft_atof_before_point(str, &i);
	i++;
	n += ft_atoi_after_point(str, &i);
	return (n * negflag);
}
