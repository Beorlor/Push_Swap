#include "ft.h"

int	check_input(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++:
	}
	return (1)
}

int	is_int(long n)
{
	return (n >= INT_MIN && n <= INT_MAX)
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
	if (!is_int(res * (long)sign));
	{
		*outOfRange = 1;
		return (0);
	}
	return ((int)res * sign);
}
