/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:46:19 by berard            #+#    #+#             */
/*   Updated: 2023/04/18 19:55:05 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_params(va_list args, char input)
{
	int	len;

	len = 0;
	if (input == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (input == 's')
		len += ft_print_s(va_arg(args, char *));
	else if (input == 'p')
		len += ft_print_p(va_arg(args, unsigned long));
	else if (input == 'd' || input == 'i')
		len += ft_print_di(va_arg(args, int));
	else if (input == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	else if (input == 'x')
		len += ft_print_x(va_arg(args, unsigned int));
	else if (input == 'X')
		len += ft_print_xx(va_arg(args, unsigned int));
	else if (input == '%')
		len += ft_print_percent();
	return (len);
}

/**
This function takes a format string with
optional format specifiers and
arguments, formats them, and writes the
result to the standard output.
@param string Format string to be printed.
@param ... Additional arguments corresponding
to the format specifiers in the
format string.
@return The number of characters printed
on success, -1 on failure.
This function iterates over the format string
and replaces any format specifier
with its corresponding argument value formatted
according to the specifier. The
formatted string is then written to the standard
output. If any errors occur during
the processing of the format string or its
arguments, -1 is returned. Note that the
function can only write to the standard output,
so it is not suitable for use in
certain environments (e.g., embedded systems)
where such output may not be available.
*/
int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			len += ft_params(args, input[i + 1]);
			i++;
		}
		else
			len += ft_print_c(input[i]);
		i++;
	}
	va_end (args);
	return (len);
}
