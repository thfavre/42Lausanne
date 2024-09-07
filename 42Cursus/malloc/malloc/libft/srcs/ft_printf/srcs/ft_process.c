/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:01:36 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/22 13:55:38 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//-----------------------------------------------------------------------------
//function name: process_int
//
//description: convert int in ascii and print
//-----------------------------------------------------------------------------
int	process_int(int nbr)
{
	char	*itoa_nbr;
	int		intlen;

	itoa_nbr = ft_itoa(nbr);
	intlen = ft_strlen(itoa_nbr);
	ft_putstr_fd(itoa_nbr, 1);
	free(itoa_nbr);
	return (intlen);
}

//-----------------------------------------------------------------------------
//function name: process_unsignedint
//
//description: convert unsignedint in ascii and print
//-----------------------------------------------------------------------------
int	process_unsigned(int nbr)
{
	char			*itoa_nbr;
	int				intlen;
	unsigned int	nbru;

	nbru = (unsigned int) nbr;
	itoa_nbr = ft_itoa_unsigned(nbru);
	intlen = ft_strlen(itoa_nbr);
	ft_putstr_fd(itoa_nbr, 1);
	free(itoa_nbr);
	return (intlen);
}
//-----------------------------------------------------------------------------
//function name: process_str
//
//description: print str 
//-----------------------------------------------------------------------------

int	process_str(char *str, int *nbr_printed, int i)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		*nbr_printed += ft_strlen(str);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		*nbr_printed += ft_strlen("(null)");
	}
	return (++i);
}
//-----------------------------------------------------------------------------
//function name: process_str
//
//description: print str 
//-----------------------------------------------------------------------------

int	process_pointer(void *pointer, int *nbr_printed, int i)
{
	char	*str;

	str = ft_ptoa(pointer);
	ft_putstr_fd(str, 1);
	*nbr_printed += ft_strlen(str) + 2;
	free(str);
	return (++i);
}
//-----------------------------------------------------------------------------
//function name: process_char
//
//description: print char
//-----------------------------------------------------------------------------

int	process_char(char c, int *nbr_printed, int i)
{
	char	str[2];

	if (c)
	{
		str[0] = (unsigned char)c;
		str[1] = 0;
		*nbr_printed = *nbr_printed + 1;
		ft_putstr_fd(str, 1);
	}
	else
	{
		write(1, "", 1);
		*nbr_printed = *nbr_printed + 1;
	}
	return (++i);
}
