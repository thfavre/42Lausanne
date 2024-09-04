/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:50 by thfavre           #+#    #+#             */
/*   Updated: 2023/02/27 11:21:21 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	send_char_to_server(int pid, int c)
{
	int	j;

	j = 0;
	while (j < BIT_NB)
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
	send_char_to_server(pid, 0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*client_pid;

	if (argc != 3)
	{
		ft_putstr_fd("The first arg should be the server pid, \
the second one the message.\n", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid == 0)
		return (1);
	client_pid = ft_itoa(getpid());
	if (client_pid == NULL)
		return (1);
	send_str_to_server(server_pid, argv[2]);
}
