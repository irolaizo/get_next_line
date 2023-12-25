
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t  ft_gnl_strlen(const char *str);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_strjoin(char const *str_left, char const *buff);
char	*ft_save_line(char *save_line);
char	*ft_make_new_line(char *create_line);
char	*ft_read_to_str(int fd, char *str_left);
char	*get_next_line(int fd);

#endif