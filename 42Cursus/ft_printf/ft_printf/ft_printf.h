/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:20:45 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/24 15:19:43 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
#include "unistd.h"

int		ft_printf(const char *format, ...);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putxnbr_fd(int	n, int fd, int maj);
void	ft_putptr_fd(void *ptr, int fd);

#endif
