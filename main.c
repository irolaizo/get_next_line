/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:33:31 by irolaizo          #+#    #+#             */
/*   Updated: 2024/01/10 19:10:21 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int   main(void)
{
	char	*line;

	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	close(fd1);
	return (0);
} */
/* int	main()
{
	char	*line;
	int		i;
	int		fd;

	fd = open("giant_line_nl.txt", O_RDONLY);
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
	//printf("line [%02d]: %s\n", i, line);
	close(fd);
	return (0);
 } */