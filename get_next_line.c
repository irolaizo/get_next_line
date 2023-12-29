/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:34:22 by irolaizo          #+#    #+#             */
/*   Updated: 2023/12/29 17:53:25 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char 		buff[BUFFER_SIZE + 1];
	static char	*storage;
	int			rd_bytes;

	line = NULL;
	rd_bytes = 0;
	storage = NULL;
	while(1)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		buff[rd_bytes] = '\0';
		storage = ft_strjoin(storage, buff);
		if(rd_bytes == -1)
			return(NULL);
		if(rd_bytes == 0)
			break;
	}
	line = ft_print_line(storage);
	storage = ft_remain(storage);
	//return(line);
	return(storage);
}