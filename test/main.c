//#include "../incl/fractol.h"
#include<math.h>
#include<stdio.h>


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
	printf("\npflag: %i\n", p_flag);
	printf("\nflag: %i\n", flag);
	if (p_flag != 1)
		return (0);
	return (flag);
}

/*Converts array to floating point number of double type*/
double	ft_atof(const char *str)
{
	int		i;
	int		negflag;
	double	n;

	if (!ft_atof_str_check(str))
		return (printf("Error!\n"), -1);
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

int	main(void)
{
	char	string[] = "test";
	char	numwl[] = "12.3456789";
	char	num[] = "01234.56.789";
	char	ln[] = "a0123456789";
	char	nl[] = "0123456789a";

	printf("%s: %f\n", string, ft_atof(string));
	printf("%s: %f\n", numwl, ft_atof(numwl));
	printf("%s: %f\n", num, ft_atof(num));
	printf("%s: %f\n", ln, ft_atof(ln));
	printf("%s: %f\n", nl, ft_atof(nl));
	return (0);
}
