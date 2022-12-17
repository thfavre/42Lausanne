/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:50 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/08 15:36:13 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	send_char_to_server(int pid, int c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((c >> j) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(CLIENT_USLEEP_TIME_US);
		j++;
	}
}

void	send_str_to_server(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char_to_server(pid, str[i++]);
	send_char_to_server(pid, 255);
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd("The first arg should be the server pid, \
						the second one the message.\n", 1);
		return (1);
	}
	if (argv[2][0] == '\0')
		return (0);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_str_to_server(pid, message);
	return (0);
}
