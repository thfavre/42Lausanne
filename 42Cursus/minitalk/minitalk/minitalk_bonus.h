/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:40 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/29 16:06:22 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

// number of bit send for each letter
# define BIT_NB 8
// time that the client will sleep after every signal he sends (in microsecond)
# define CLIENT_USLEEP_TIME_US 59

typedef struct s_letter
{
	unsigned int	current_bit;
	int				ascii;
}					t_letter;

typedef struct s_data
{
	t_letter	letter;
	char		*sentense;
	int			sentense_nb;
}					t_data;

#endif
