/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:05:11 by yassinebens       #+#    #+#             */
/*   Updated: 2022/11/28 15:05:41 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

///-----------------------------------------------------------------------------
//function name: process_hex
//
//description: convert hex into ascii and print
///-----------------------------------------------------------------------------
int	process_hex(unsigned int hex_value, int *nbr_printed, int maj, int j)
{
	char	*str;
	int		i;

	i = 0;
	if (!hex_value)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = '0';
		ft_putstr_fd(str, 1);
	}
	else
	{
		str = ft_calloc(hex_len(hex_value) + 1, sizeof(char));
		while (hex_value >= 16)
		{
			str[i++] = ft_itoh(hex_value % 16, maj);
			hex_value /= 16;
		}
		if (hex_value > 0)
			str[i] = ft_itoh(hex_value, maj);
		ft_putstr_fd(ft_strrev(str), 1);
	}
	*nbr_printed += ft_strlen(str);
	free(str);
	return (++j);
}

//-----------------------------------------------------------------------------
//function name: print_str
//
//description: print str of format until next '%' or next '\' or '\0'
//-----------------------------------------------------------------------------
int	print_str(const char *format, int i, int *nbr_printed)
{
	char	*str;
	int		start;

	start = i;
	while (format[i] && (format[i] != '%'))
	{
		i++;
		*nbr_printed = *nbr_printed + 1;
	}
	str = ft_calloc(i - start + 1, sizeof(char));
	ft_strlcpy(str, format + start, i + 1 - start);
	ft_putstr_fd(str, 1);
	free(str);
	return (i);
}

//-----------------------------------------------------------------------------
//function name: process percentage
//
//description: print %
//-----------------------------------------------------------------------------
int	process_percentage(int i, int *nbr_printed)
{
	ft_putstr_fd("%", 1);
	*nbr_printed = *nbr_printed + 1;
	return (++i);
}
