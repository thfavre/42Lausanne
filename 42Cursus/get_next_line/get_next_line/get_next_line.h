#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
//# endif

# include <stdlib.h>
# include <stdio.h> //TODO delete this
# include <unistd.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;

}	t_list;

t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif

