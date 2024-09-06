/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:24:54 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/22 13:55:02 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//-----------------------------------------------------------------------------
//function name: pointer_len
//
//description: count the number of needed characters to print pointer address
//-----------------------------------------------------------------------------

int	pointer_len(void *pointer)
{
	int				i;
	unsigned long	pointeradd;

	pointeradd = (unsigned long)pointer;
	i = 0;
	while (pointeradd > 16)
	{
		pointeradd /= 16;
		i++;
	}
	if (pointeradd > 0)
		i++;
	return (i);
}

//-----------------------------------------------------------------------------
//function name: hex_len
//
//description: count the number of needed characters to print hex value
//-----------------------------------------------------------------------------

int	hex_len(unsigned int hex)
{
	int	i;

	i = 0;
	while (hex >= 16)
	{
		hex /= 16;
		i++;
	}
	if (hex > 0)
		i++;
	return (i);
}

//-----------------------------------------------------------------------------
//function name: format_parse
//
//description: identify printf format
//-----------------------------------------------------------------------------

int	format_parse(const char *format, int i, va_list *ap, int *nbr_printed)
{
	i++;
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
	{
		if (format[i] != 'u')
			*nbr_printed += process_int(va_arg(*ap, int));
		else
			*nbr_printed += process_unsigned(va_arg(*ap, int));
		i++;
	}
	else if (format[i] == 's')
		i = process_str(va_arg(*ap, char *), nbr_printed, i);
	else if (format[i] == 'c')
		i = process_char(va_arg(*ap, int), nbr_printed, i);
	else if (format[i] == '%')
		i = process_percentage(i, nbr_printed);
	else if (format[i] == 'p')
	{
		ft_putstr_fd("0x", 1);
		i = process_pointer(va_arg(*ap, void *), nbr_printed, i);
	}
	else if (format[i] == 'x')
		i = process_hex(va_arg(*ap, int), nbr_printed, 0, i);
	else if (format[i] == 'X')
		i = process_hex(va_arg(*ap, int), nbr_printed, 1, i);
	return (i);
}
