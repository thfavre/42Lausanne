/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:01:55 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/22 13:52:31 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		process_int(int nbr);
int		process_unsigned(int nbr);
int		process_str(char *str, int *nbr_printed, int i);
int		process_pointer(void *pointer, int *nbr_printed, int i);
int		process_char(char c, int *nbr_printed, int i);
int		process_hex(unsigned int hex_value, int *nbr_printed, int maj, int j);
int		print_str(const char *format, int i, int *nbr_printed);
int		pointer_len(void *pointer);
char	ft_itoh(long nbr, int maj);
char	*ft_ptoa(void *pointer);
int		hex_len(unsigned int hex);
int		format_parse(const char *format, int i, va_list *ap, int *nbr_printed);
int		ft_printf(const char *format, ...);
int		process_percentage(int i, int *nbr_printed);

#endif
