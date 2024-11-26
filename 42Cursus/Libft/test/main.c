#include "libft.h"
#include <fcntl.h> // For open and O_* constants
#include <unistd.h> // For close

void print_list_content_to_fd(void *content, int fd)
{
    ft_fprintf(fd, "%s\n", (char *)content);
}

int main()
{
    // Open or create the file "test.txt" with write permissions
    int file_fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd == -1)
    {
        ft_fprintf(2, "Error: Unable to open or create test.txt\n");
        return 1;
    }

    // Create and populate the list
    t_list *lst = ft_lstnew("test2");
    ft_lstadd_back(&lst, ft_lstnew("test1"));
    ft_lstadd_back(&lst, ft_lstnew("test4"));
    ft_lstadd_back(&lst, ft_lstnew("test3"));
    ft_lstadd_back(&lst, ft_lstnew("test31"));

    // Sort the list
    ft_lstsort(lst, ft_lstsort_cmpft_str, false);

    // Write the sorted list to the file
    t_list *current = lst;
    while (current)
    {
        print_list_content_to_fd(current->content, file_fd);
        print_list_content_to_fd(current->content, 1);
        current = current->next;
    }

    // Close the file
    close(file_fd);

    return 0;
}
