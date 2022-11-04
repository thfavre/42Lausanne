#include<stdio.h>
#include "Libft/libft.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	write(1, &ptr, 5);//test
	//ft_putstr_fd((void *)ptr, fd);
}