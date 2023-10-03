/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:20:07 by smelicha          #+#    #+#             */
/*   Updated: 2023/10/03 11:58:12 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

double	ft_atof_before_point(const char *str, int *i)
{
	double	n;

	n = 0.0;
	while ((str[*i] >= '0' && str[*i] <= '9') && (str[*i] != '.'
			|| str[*i] != '\0'))
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

/*Checks if the string is valid, if it contains only numbers and one period*/
int	ft_atof_str_check(const char *str)
{
	int	i;
	int	flag;
	int	p_flag;

	i = 0;
	flag = 1;
	p_flag = 0;
	while (str[i] != '\0' && flag == 1)
	{
		if (!((str[i] < '0' || str[i] > '9') || (str[i] != '.')))
			flag = 0;
		i++;
		if (str[i] == '.')
			p_flag++;
	}
	if (p_flag != 1)
		return (0);
	return (flag);
}

/*Converts array to floating point number of double type*/
double	ft_atof(const char *str, t_dt *dt)
{
	int		i;
	int		negflag;
	double	n;

	if (!ft_atof_str_check(str))
		ft_error(0, dt);
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

/*Compares two strings, if they are same, returns length of those strings,
if strings are different returns 0*/
int	ft_match(const char *str1, const char *str2)
{
	int	i;
	int	j;
	int	k;

	if (str1 == NULL || str2 == NULL)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (str1[j] != '\0')
		j++;
	while (str2[k] != '\0')
		k++;
	while ((str1[i] == str2[i]) && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	if (j == k && j == i)
		return (i);
	else
		return (0);
}
