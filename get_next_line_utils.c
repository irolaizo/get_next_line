/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:28:49 by irolaizo          #+#    #+#             */
/*   Updated: 2023/12/29 18:07:05 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}
char *ft_strjoin(char *storage, char *buff)
{
	int		i;
	int 	k;
	char 	*temp;
	
	if(storage == NULL && buff == NULL)
		return(NULL);
	temp = NULL;
	temp = malloc(sizeof(char )*(ft_strlen(storage) + ft_strlen(buff)+1));
	if(temp == NULL)
		return (NULL);
	i = -1;
	while (storage && storage[++i])
		temp[i] = storage[i];
	k = 0;
	while (buff && buff[k])
		temp[i++] = buff[k++];
	temp[i] = '\0';
	if(storage != NULL)
	{
		free(storage);
		storage=NULL;
	}
	storage = temp;
	return (storage);
}
char	*ft_print_line(char *storage)
{
    int i;
    int j;
    char *line;

    i = 0;
    if (storage == NULL)
        return (NULL);
    while (storage && storage[i] && storage[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * (i + 2));
    if (line == NULL)
        return (NULL);
    j = 0;
	while (storage[j] && storage[j] != '\n')
	{
		line[j] = storage[j];
		j++;
	}
	if (storage[j] == '\n')
	{
		line[j] = storage[j];
		j++;
	}
	line[j] = '\0';
	return (line);	
}

char *ft_remain(char *storage)
{
	int	i;
	int j;
	char *new_storage;
	
	if (storage == NULL)
		return (NULL);
	new_storage = NULL;
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	new_storage = malloc(sizeof(char) * ft_strlen(storage) + 1 - i);
	if (!new_storage)
		return (NULL);
	j = 0;
	i = 0;
    while (storage && storage[i])
        new_storage[j++] = storage[i++];
    new_storage[j] = '\0';
    free (storage);
    return (new_storage);
}
