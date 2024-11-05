#include "ft_ls.h"
#include <stdio.h>
#include <errno.h>
 #include <pwd.h>
#include <grp.h>
#include <time.h>


char	*get_date(const time_t *timep);

void    print_entities_long_format(t_list *entities, t_options *options, long total_blocks) {
	t_list  *tmp_lst;

	ft_printf("total %d\n", total_blocks/2);

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

		ft_printf("%c", file_type);

		// User permissions
		ft_printf("%c", (mode & S_IRUSR) ? 'r' : '-'); // Read permission
		ft_printf("%c", (mode & S_IWUSR) ? 'w' : '-'); // Write permission
		ft_printf("%c", (mode & S_IXUSR) ? 'x' : '-'); // Execute permission

		// Group permissions
		ft_printf("%c", (mode & S_IRGRP) ? 'r' : '-');
		ft_printf("%c", (mode & S_IWGRP) ? 'w' : '-');
		ft_printf("%c", (mode & S_IXGRP) ? 'x' : '-');

		// Other permissions
		ft_printf("%c", (mode & S_IROTH) ? 'r' : '-');
		ft_printf("%c", (mode & S_IWOTH) ? 'w' : '-');
		ft_printf("%c", (mode & S_IXOTH) ? 'x' : '-');

		// number of hard link
		ft_printf("  %ld", entity->entity_stat.st_nlink);

		// Get user name from UID
		struct passwd *pw = getpwuid(entity->entity_stat.st_uid);
		if (pw != NULL) {
			ft_printf(" %s", pw->pw_name);
		} else {
			perror("getpwuid");
		}

		// Get group name from GID
		struct group *gr = getgrgid(entity->entity_stat.st_gid);
		if (gr != NULL) {
			ft_printf(" %s", gr->gr_name);
		} else {
			perror("getgrgid");
		}

		// byte size
		ft_printf(" %d", entity->entity_stat.st_size);

		// date
		ft_printf(" %s ", get_date(&entity->entity_stat.st_mtime));

		// entity name
		print_entity_name(entity);

		ft_printf("\n");
		tmp_lst = entities;
		entities = entities->next;
		// FREEls
		ft_lstdelone(tmp_lst, free);
	}
}

char	*get_date(const time_t *timep) {
	char *time = ctime(timep);
	
	time[4 + 12] = '\0'; // remove the year
	time += 4; // skip the day name
	return (time);
}