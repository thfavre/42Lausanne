#include <time.h>
#include "libft.h"


// char	*get_date(const time_t *timep) {
// 	char *long_time = ctime(timep);
// 	long_time[4 + 12] = '\0';
// 	long_time += 4; // skip the day name
// 	// char	*shorter_time;
// 	// char	*ptr;
// 	// char	*year;

// 	// shorter_time = (char *)malloc(sizeof(char) * 12);
// 	// if (!shorter_time)
// 	// 	return (NULL);
// 	// ptr = long_time + 4;
// 	// ptr[20] = '\0';
// 	// year = ft_strdup(ptr + 15);
// 	// shorter_time = ft_strncpy(shorter_time, ptr, 7);
// 	// shorter_time[7] = '\0';
// 	// ptr = shorter_time;
// 	// shorter_time = ft_strjoin(shorter_time, year);
// 	// free(ptr);
// 	// // printf("2 %s}", shorter_time);
// 	return (long_time);
// }
