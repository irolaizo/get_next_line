/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irolaizo <irolaizo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:03:04 by irolaizo          #+#    #+#             */
/*   Updated: 2024/01/12 18:24:49 by irolaizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buff)
{
	size_t		i;
	size_t		k;
	size_t		len;
	char		*temp;

	if (storage == NULL && buff == NULL)
		return (NULL);
	temp = NULL;
	len = ft_strlen(storage) + ft_strlen(buff);
	temp = malloc(sizeof(char ) * (len + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (storage[i])
	{
		temp[i] = storage[i];
		i++;
	}
	temp[i] = '\0';
	k = 0;
	while (buff != NULL && buff[k] != '\0')
		temp[i++] = buff[k++];
	temp[i] = '\0';
	return (free(storage), temp);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
