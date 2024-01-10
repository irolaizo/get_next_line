/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:34:22 by irolaizo          #+#    #+#             */
/*   Updated: 2024/01/10 18:20:45 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *storage)
{
	char *temp_storage;
	int	 bytes_read;

	temp_storage = NULL;
	temp_storage = malloc((BUFFER_SIZE +1) * sizeof(char));
	if (temp_storage == NULL)
		return (NULL);
	bytes_read = 1;
	while((ft_strchr(storage,'\n') == NULL)  && bytes_read != 0)
	{
		bytes_read = read(fd, temp_storage, BUFFER_SIZE);
		if(bytes_read < 0)
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
	static char	*storage;

	storage = ft_read_file(fd, storage);
	if (storage == NULL)
		return (NULL);
	line = ft_print_line(storage);
	storage = ft_remain(storage);
	return(line);
}