
#include "push_swap.h"

int	ascii_to_int(char *str)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		//if (*str < '0' || *str > 9)
		//	return (NULL); //what to return ?
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (sign * nb);
}


bool	is_str_integer_number(char *str)
{
	long	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '\0')
		return (false);
	while (*str)
	{
		//if (*str < '0' || *str > 9)
		//	return (NULL); //what to return ?
		nb *= 10;
		nb += *str - '0';
		if (*str < '0' || *str > '9' || nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (false);
		str++;
	}
	return (true);
}
