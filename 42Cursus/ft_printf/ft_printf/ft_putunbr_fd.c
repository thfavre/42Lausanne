#include "Libft/libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putunbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10 + '0'), fd);
}