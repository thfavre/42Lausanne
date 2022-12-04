
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
