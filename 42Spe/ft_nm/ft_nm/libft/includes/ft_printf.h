/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:37:15 by thfavre           #+#    #+#             */
/*   Updated: 2024/11/26 21:31:07 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *input, ...);
int	ft_fprintf(int fd, const char *input, ...);

// int ft_vsprintf(char *str, const char *format, va_list args);
// int ft_vsnprintf(char *str, size_t size, const char *format, va_list args);
int	ft_vfprintf(int fd, const char *input, va_list args);
int	ft_fprint_c(int c, int fd);
int	ft_fprint_s(char *str, int fd);
int	ft_fprint_percent(int fd);
int	ft_fprint_di(int n, int fd);
int	ft_fprint_u(unsigned int n, int fd);
int	ft_fprint_x(unsigned int n, int fd);
int	ft_fprint_xx(unsigned int n, int fd);
int	ft_fprint_p(unsigned long n, int fd);
#endif
