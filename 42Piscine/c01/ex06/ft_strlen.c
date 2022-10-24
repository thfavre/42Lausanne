/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:04:40 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/01 23:11:47 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str)
	{
		str++;
		++strlen;
	}
	return (strlen);
}
/*
int main(){
	int t = ft_strlen("test123");
	printf("%d", t);
}*/
