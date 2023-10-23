#include "ft.h"

int	check_input(char *str_numb[])
{
	int	i;
	int	j;

	i = 1;
	while (str_numb[i])
	{
		j = 0;
		if (str_numb[i][0] == '-' || str_numb[i][0] == '+')
			j++;
		while (str_numb[i][j])
		{
			if (!(str_numb[i][j] >= '0' && str_numb[i][j] <= '9'))
			{
				free_str_numb(str_numb);
				write(2, "Wrong Format\n", 13);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_int(long n)
{
	return (n >= INT_MIN && n <= INT_MAX);
}

int	ft_atoi(char *s, int *outOfRange)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		++i;
	}
	while ('0' <= s[i] && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		++i;
	}
	if (is_int(res * (long)sign) == 0)
	{
		*outOfRange = 1;
		return (0);
	}
	return ((int)res * sign);
}
