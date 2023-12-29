/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:34:28 by irolaizo          #+#    #+#             */
/*   Updated: 2023/12/29 18:06:42 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef	 BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

/*GNL*/
char	*get_next_line(int fd);
/*UTILS*/
size_t	ft_strlen(const char *s);
char *ft_strjoin(char *storage, char *buff);
char	*ft_print_line(char *storage);
char *ft_remain(char *storage);

#endif