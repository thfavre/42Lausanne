/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:40 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/08 15:37:17 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft/libft.h"

// time that the client will sleep after every signal he sends (in microsecond)
# define CLIENT_USLEEP_TIME_US 50

typedef struct s_letter
{
	unsigned int	current_bit;
	int				letter;
}					t_letter;

typedef struct s_word
{
	t_letter	letter;
	char		*word;
}					t_word;

#endif
