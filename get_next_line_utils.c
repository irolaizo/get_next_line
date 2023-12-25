
#include "get_next_line.h"

size_t ft_gnl_strlen(const char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	int i;
	
	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
	{
		i++;
		return((const char *)&s[i]);
	}	
	else
		return(NULL);
}

char	*ft_strjoin(char const *str_rd, char const *buff)
{
	int	i;
	int	j;
	int	leng_total;
	char str_of_both;

	if (!str_rd || !buff)
		return (NULL);
	leng_total = (char *)malloc(ft_gnl_strlen(str_rd) + ft_gnl_strlen(buff));
	i = 0;
	while (str_rd[i])
	{
		str_of_both[i] = str_rd[i];
		i++;
	}
	j = 0;
	while(buff[j])
		str_of_both[i + j] = buff[j];
	str_of_both[i + j] = '\0';
	free (leng_total);
	return (str_of_both);
}