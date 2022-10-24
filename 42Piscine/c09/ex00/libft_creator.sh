# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 13:14:42 by thfavre           #+#    #+#              #
#    Updated: 2022/09/21 13:32:39 by thfavre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a

find . -name "*.c" -type f -maxdepth 1 -exec gcc -Wall -Werror -Wextra -c {} \;

ar -rcs libft.a *.o 

find . -name "*.o" -type f -maxdepth 1 -delete
