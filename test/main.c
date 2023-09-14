#include "../incl/fractol.h"
#include<stdio.h>

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

int	ft_match(const char *str1, const char *str2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str1[j] != '\0')
		j++;
	while (str2[k] != '\0')
		k++;
	while (str1[i] == str2[i])
		i++;
	if (j == k && j == i)
		return (i);
	else
		return (0);
}

int	ft_char_comp(const char *test, const char *set)
{
	int	i;
	int	j;
	int	

	i = 0;
	j = 0;
	while (test[i] != '\0')
	{
		while (set[j] != '\0')
			if (set[j] == test[i])
			if (set[j + 1] == '\0')
				return (0);
	}
}

int	ft_is_str_nr(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	while (str[*i] >= '0' && str[*i] <= '9')
}


int	main()
{
	double	n;
	char	test[] = "0.123";

	n = 0.0;
	n = ft_atof(test);
	printf("%3.5f\n", n);
	printf("%i\n", ft_match(test, "0.223"));
	return (0);
}