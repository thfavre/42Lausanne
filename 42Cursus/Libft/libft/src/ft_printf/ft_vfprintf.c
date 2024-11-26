/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:12:13 by thfavre           #+#    #+#             */
/*   Updated: 2024/11/26 19:12:13 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_params(va_list args, char input, int fd)
{
	int	len;

	len = 0;
	if (input == 'c')
		len += ft_fprint_c(va_arg(args, int), fd);
	else if (input == 's')
		len += ft_fprint_s(va_arg(args, char *), fd);
	else if (input == 'p')
		len += ft_fprint_p(va_arg(args, unsigned long), fd);
	else if (input == 'd' || input == 'i')
		len += ft_fprint_di(va_arg(args, int), fd);
	else if (input == 'u')
		len += ft_fprint_u(va_arg(args, unsigned int), fd);
	else if (input == 'x')
		len += ft_fprint_x(va_arg(args, unsigned int), fd);
	else if (input == 'X')
		len += ft_fprint_xx(va_arg(args, unsigned int), fd);
	else if (input == '%')
		len += ft_fprint_percent(fd);
	return (len);
}

int	ft_vfprintf(int fd, const char *input, va_list args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			len += ft_params(args, input[i + 1], fd);
			i++;
		}
		else
			len += ft_fprint_c(input[i], fd);
		i++;
	}
	return (len);
}
