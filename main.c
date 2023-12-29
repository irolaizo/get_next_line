/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:33:31 by irolaizo          #+#    #+#             */
/*   Updated: 2023/12/29 16:45:37 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int   main(void)
{
	char	*line;

	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	close(fd1);
	return (0);
}