/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:48:17 by berard            #+#    #+#             */
/*   Updated: 2022/11/14 13:33:17 by berard           ###   ########.fr       */
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
int	ft_print_c(int c);
int	ft_print_s(char *str);
int	ft_print_percent(void);
int	ft_print_di(int n);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned int n);
int	ft_print_xx(unsigned int n);
int	ft_print_p(unsigned long n);

#endif
