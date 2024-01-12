/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:03:53 by irolaizo          #+#    #+#             */
/*   Updated: 2024/01/12 18:18:51 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/syslimits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*GNL*/
char	*get_next_line(int fd);
char	*ft_to_line(char *storage);
char	*ft_read_file(int fd, char *storage);
char	*ft_remain(char *storage);
/*UTILS*/
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *storage, char *buff);
char	*ft_strchr(char *s, int c);

#endif