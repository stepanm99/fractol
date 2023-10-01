#include "../incl/fractol.h"
#include<math.h>
#include<stdio.h>


int	ft_int_str_check(const char *str)
{
	int	i;
	int	flag;
	int	p_flag;

	i = 0;
	flag = 0;
	p_flag = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') || (str[i] != '.'))
			flag = 1;
		i++;
		if (str[i] == '.')
			p_flag++;
	}
	if (p_flag != 1)
		return (0);
	return (flag);
}

int	main(void)
{
	char	string[] = "test";
	char	numwl[] = "12e3456789";
	char	num[] = "01234.56.789";
	char	ln[] = "a0123456789";
	char	nl[] = "0123456789a";

	printf("%s: %i\n", string, ft_int_str_check(string));
	printf("%s: %i\n", numwl, ft_int_str_check(numwl));
	printf("%s: %i\n", num, ft_int_str_check(num));
	printf("%s: %i\n", ln, ft_int_str_check(ln));
	printf("%s: %i\n", nl, ft_int_str_check(nl));
	return (0);
}
