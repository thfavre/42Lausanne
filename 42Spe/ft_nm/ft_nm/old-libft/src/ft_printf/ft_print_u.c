/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:35:21 by berard            #+#    #+#             */
/*   Updated: 2022/11/14 17:51:51 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizemalloc(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		i;

	i = ft_sizemalloc(n);
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == 0)
		return (NULL);
	ptr[i] = '\0';
	if (n == 0)
		ptr[0] = 48;
	while (n != '\0')
	{
		ptr[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (ptr);
}

int	ft_print_u(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_uitoa(n);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}
