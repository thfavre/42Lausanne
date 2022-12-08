/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:33:43 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/08 15:33:53 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	modify_bit(int *nb, int pos, int bit_value)
{
	int	mask;

	mask = 1 << pos;
	*nb = (*nb & ~mask) | (bit_value << pos);
}

char	*ft_join_char_to_str(char *s, char c)
{
	char	*new_s;
	size_t	s_len;
	size_t	c_len;

	s_len = ft_strlen(s);
	c_len = 1;
	new_s = malloc(sizeof(*s) * (s_len + c_len + 1));
	if (s != NULL)
	{
		ft_memcpy(new_s, s, s_len);
		new_s[s_len] = c;
		new_s[s_len + c_len] = '\0';
	}
	return (new_s);
}

void	handle_sigusr(int sig)
{
	static t_word	word = {(t_letter){0, 0}, ""};

	if (sig == SIGUSR1)
		modify_bit(&word.letter.letter, word.letter.current_bit, 1);
	else if (sig == SIGUSR2)
		modify_bit(&word.letter.letter, word.letter.current_bit, 0);
	if (word.letter.current_bit == 8 - 1)
	{
		if (word.letter.letter == 255)
		{
			write(1, "\n", 1);
			write(1, word.word, ft_strlen(word.word));
			free(word.word);
			word.word = "";
		}
		else
			word.word = ft_join_char_to_str(word.word, word.letter.letter);
		word.letter.current_bit = 0;
	}
	else
		word.letter.current_bit++;
}

int	main(void)
{
	char				*pid;
	struct sigaction	sa1;
	struct sigaction	sa2;

	pid = ft_itoa(getpid());
	if (pid == NULL)
		return (1);
	write(1, "Server PID : ", 13);
	ft_putstr_fd(pid, 1);
	free(pid);
	sa1 = (struct sigaction){0};
	sigemptyset(&sa1.sa_mask);
	sigaddset(&sa1.sa_mask, SIGUSR2);
	sa1.sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2 = (struct sigaction){0};
	sigemptyset(&sa2.sa_mask);
	sigaddset(&sa2.sa_mask, SIGUSR1);
	sa2.sa_handler = &handle_sigusr;
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		pause();
	return (0);
}
