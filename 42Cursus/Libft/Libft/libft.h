/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:08:32 by thfavre           #+#    #+#             */
/*   Updated: 2022/10/27 16:14:00 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

// Part 1
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(char *src);
void	ft_bzero(void *s, size_t n);
int		ft_isascii(int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// Part 2

// Bonus

#endif