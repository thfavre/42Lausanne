/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:44:56 by jchapell          #+#    #+#             */
/*   Updated: 2022/09/21 23:18:53 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

# include "level.h"

int		is_num(char c);
int		str_num_size(char *str);
int		power(int a, int b);
int		char_to_int(char c);
int		ft_atoi(char *str);
int		ft_ischarprintable(char c);
int		print_error(int n);
int		ft_strlen(char *str);
int		parse_validity(char *parsed, t_data data);
void	draw_bigger_square(t_level level, int x);
char	*parse(char *file_path);
char	*read_stdin(void);
int		print_errors(int n, char *frees);
t_level	parse_level(char *unparsed);

#endif
