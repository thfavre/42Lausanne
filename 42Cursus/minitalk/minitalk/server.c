/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:43 by thfavre           #+#    #+#             */
/*   Updated: 2023/02/27 11:39:54 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	modify_bit(int *nb, int pos, int bit_value)
{
	int	mask;

	mask = 1 << pos;
	*nb = (*nb & ~mask) | (bit_value << pos);
}

char	*ft_join_char_str(char *s, char c)
{
	char	*new_s;
	size_t	s_len;

	s_len = ft_strlen(s);
	new_s = malloc(sizeof(*s) * (s_len + 1 + 1));
	if (s != NULL)
	{
		ft_memcpy(new_s, s, s_len);
		new_s[s_len] = c;
		new_s[s_len + 1] = '\0';
	}
	return (new_s);
}

void	handle_sigusr(int sig)
{
	static t_data	data = {(t_letter){0, 0}, ""};

	if (sig == SIGUSR1)
		modify_bit(&data.letter.ascii, data.letter.current_bit, 1);
	else if (sig == SIGUSR2)
		modify_bit(&data.letter.ascii, data.letter.current_bit, 0);
	if (data.letter.current_bit == BIT_NB - 1)
	{
		if (data.letter.ascii == 0)
		{
			write(1, data.sentense, ft_strlen(data.sentense));
			data.sentense = "";
		}
		else
			data.sentense = ft_join_char_str(data.sentense, data.letter.ascii);
		data.letter.current_bit = 0;
	}
	else
		data.letter.current_bit++;
}

int	main(void)
{
	char				*pid;
	struct sigaction	sa;

	pid = ft_itoa(getpid());
	if (pid == NULL)
		return (1);
	write(1, "Server PID : ", 13);
	ft_putstr_fd(pid, 1);
	free(pid);
	sa = (struct sigaction){0};
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = &handle_sigusr;
	sigaction(SIGKILL, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
