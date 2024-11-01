#include "ft_ls.h"
#include <stdio.h>
#include <errno.h>
 #include <pwd.h>
#include <grp.h>
#include <time.h>
void print_entities(t_list *entities, t_options *options) {
    // ft_lstsort(all_dirents, lst_compare_fn_dirent_str, options->r);
        // ft_printf("COLOR_RESET\n");

    while (entities && entities->content) {
        const t_entity *entity = (const t_entity *)entities->content;
        const struct dirent *dir_entry = &entity->dir_entry;//(const struct dirent *)all_dirents->content->dir_entry;
        if (dir_entry->d_type == DT_DIR)
            ft_printf(BOLD_BLUE);
        else if (dir_entry->d_type == DT_LNK)
            ft_printf(BOLD_CYAN);
        else
            ft_printf(COLOR_RESET);

        ft_printf("%s\t", dir_entry->d_name);
        ft_printf(COLOR_RESET);
        entities = entities->next;
    }
    ft_printf("\n");
}

// ! TODO put in other/new file
void    print_entities_long_format(t_list *entities, t_options *options, long total_blocks) {
    // ft_lstsort(all_dirents, lst_compare_fn_dirent_str, options->r);
    // ft_printf("total %d\n", total_blocks/2);
    while (entities && entities->content) {
        const t_entity *entity = (const t_entity *)entities->content;
        char file_type;
        mode_t mode =  entity->entity_stat.st_mode;
        // Determine the file type (regular file, directory, etc.)
        if (S_ISREG(mode)) file_type = '-';      // Regular file
        else if (S_ISDIR(mode)) file_type = 'd'; // Directory
        else if (S_ISLNK(mode)) file_type = 'l'; // Symbolic link
        else if (S_ISCHR(mode)) file_type = 'c'; // Character device
        else if (S_ISBLK(mode)) file_type = 'b'; // Block device
        else if (S_ISFIFO(mode)) file_type = 'p';// FIFO (named pipe)
        else if (S_ISSOCK(mode)) file_type = 's';// Socket
        else file_type = '?';                    // Unknown file type

        printf("%c", file_type);

        // User permissions
        printf("%c", (mode & S_IRUSR) ? 'r' : '-'); // Read permission
        printf("%c", (mode & S_IWUSR) ? 'w' : '-'); // Write permission
        printf("%c", (mode & S_IXUSR) ? 'x' : '-'); // Execute permission

        // Group permissions
        printf("%c", (mode & S_IRGRP) ? 'r' : '-');
        printf("%c", (mode & S_IWGRP) ? 'w' : '-');
        printf("%c", (mode & S_IXGRP) ? 'x' : '-');

        // Other permissions
        printf("%c", (mode & S_IROTH) ? 'r' : '-');
        printf("%c", (mode & S_IWOTH) ? 'w' : '-');
        printf("%c", (mode & S_IXOTH) ? 'x' : '-');

        // number of hard link
        printf("  %ld", entity->entity_stat.st_nlink);

        // Get user name from UID
        struct passwd *pw = getpwuid(entity->entity_stat.st_uid);
        if (pw != NULL) {
            printf(" %s", pw->pw_name);  // Print the user name
        } else {
            perror("getpwuid");
        }

        // Get group name from GID
        struct group *gr = getgrgid(entity->entity_stat.st_gid);
        if (gr != NULL) {
            printf(" %s", gr->gr_name);  // Print the group name
        } else {
            perror("getgrgid");
        }

        // byte size
        printf(" %ld", entity->entity_stat.st_size);


        // date and time
        // char *time_str = ctime(&entity->entity_stat.st_mtime);
        // printf("   %ld   ", entity->entity_stat.st_mtime);
        // ! TODO set as same forat as ls -l time
        printf("Modification time  = %sd", ctime(&entity->entity_stat.st_mtime));

        // Example: "Tue Oct 10 15:32:45 2023\n"
        // We need to extract: "Oct 10 15:32"

        // Extract month (Oct), day (10), and time (15:32)
        // char output[13];
        // output[0] = '\0';  // Initialize the output string

        // Copy the month, day, and time to the output buffer
        // time_str[4..10] is "Oct 10" and time_str[11..15] is "15:32"
        // strncat(output, &time_str[4], 7);  // "Oct 10"
        // strncat(output, &time_str[11], 6); // " 15:32"

        // Write the result to stdout
        // printf(" %s", output);

        // entity name
        // TODO in color (make a function)
        printf(" %s", entity->dir_entry.d_name);

        printf("\n");
        entities = entities->next;
    }

}

void process_entity(const char *dirname, struct dirent *dir_entry, t_list **directories, t_list **entities, long *total_blocks, t_options *options) {
    if (!options->a && dir_entry->d_name[0] == '.') return;

    char path[1000] = { 0 };
    ft_strlcat(path, dirname, 1000);
    ft_strlcat(path, "/", 1000);
    ft_strlcat(path, dir_entry->d_name, 1000);

    if (dir_entry->d_type == DT_DIR && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
        handle_directory(path, directories);
    }

    struct stat entity_stat;
    // t_entity entity;
    t_entity *entity = malloc(sizeof(t_entity)); // TODO free
    if (handle_file(path, &entity_stat, total_blocks) == 0) {
        entity->dir_entry = *dir_entry;
        entity->entity_stat = entity_stat;
        ft_lstadd_back(entities, ft_lstnew(entity));
    } // ? TODO something on error?
}
