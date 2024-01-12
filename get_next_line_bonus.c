/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:03:07 by irolaizo          #+#    #+#             */
/*   Updated: 2024/01/12 19:11:52 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_to_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = NULL;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remain(char *storage)
{
	int		i;
	int		j;
	int		len;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (free(storage), NULL);
	new_storage = NULL;
	len = ft_strlen(storage);
	new_storage = (char *)malloc((len - i) * sizeof(char));
	if (!new_storage)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free (storage);
	return (new_storage);
}

char	*ft_read_file(int fd, char *storage)
{
	char	*temp_storage;
	int		bytes_read;

	temp_storage = NULL;
	temp_storage = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_storage)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp_storage, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp_storage), free(storage), NULL);
		temp_storage[bytes_read] = '\0';
		storage = ft_strjoin(storage, temp_storage);
	}
	free (temp_storage);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[OPEN_MAX];

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (storage[fd])
		{
			free(storage[fd]);
			storage[fd] = NULL;
		}
		return (NULL);
	}
	if (!storage[fd])
	{
		storage[fd] = malloc(sizeof(char));
		storage[fd][0] = '\0';
	}
	storage[fd] = ft_read_file(fd, storage[fd]);
	if (storage[fd] == NULL)
		return (NULL);
	line = ft_to_line(storage[fd]);
	storage[fd] = ft_remain(storage[fd]);
	return (line);
}

/* int	main()
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
 } */