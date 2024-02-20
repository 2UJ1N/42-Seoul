#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char	*ft_strdup(const char *s1);
int	    ft_strchr(const char *s);
char	*ft_strjoin(char const *tmp, char const *buffer);
int	    ft_strlen(const char *s);
char	*ft_substr(char const *s, int start, int end);

void    free_memory(char **backup, char **line);
int     print_line(char **backup, char **line);
int     update_buffer(int fd, ssize_t *idx, char **backup);
char    *get_next_line(int fd);

#endif