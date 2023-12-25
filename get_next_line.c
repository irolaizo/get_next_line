
#include "get_next_line.h"

char	*ft_save_line(char *save_line)
{
	int     i;
    char   *str_save;

    if (!save_line == '\0')
        return (NULL);
    i = 0;
    if (save_line[i])
    {
        str_save[i] == save_line[i];
        i++;
    }
    str_save = (char *)malloc(sizeof(char) + i);
    if (!str_save)
        return (NULL);
    while (save_line[i] && save_line[i] != '\n')
    {
        str_save[i] = save_line[i];
        i++;
    }
    str_save[i] == '\0';
    return (str_save);
}

char	*ft_make_new_line(char *create_line)
{
    int i;
    int j;
    char *str;

    i = 0;
    if (create_line[i] && create_line[i] != '\n')
        i++;
    if (create_line[i])
        return (NULL);
    str = (char *)malloc(sizeof(char) * (ft_gnl_strlen(create_line)) + 1);
    if (!str)
        return (NULL);
    j = 0;
    while (create_line[i])
    {
        str[j] = create_line[i];
        i++;
        j++;
    }
    create_line[i] = '\0';
    free (create_line);
    return (create_line);
}

char	*ft_read_to_str(int fd, char *str_all)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 0;
	while (!ft_strchr(str_all, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == 0)
		{
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str_all = ft_strjoin(str_all, buff);
	}
	free(buff);
	return (str_all);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_rd_all;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_rd_all = ft_read_to_left_str(fd, str_rd_all);
	if (!str_rd_all)
		return (NULL);
	line = ft_save_line(str_rd_all);
	str_rd_all = ft_make_new_line(str_rd_all);
	return (line);
}