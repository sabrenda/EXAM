#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char s2)
{
	int		j = 0;
	char	*str = NULL;
	str = (char *)malloc(ft_strlen(s1) + 2); //malloc
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	str[j++] = s2;
	str[j] = '\0';
	free (s1);
	s1 = NULL;
	return (str);
}
int	get_next_line(char **line)
{
	int read_s = 0;
	char buffer;
	*line = (char *)malloc(1); // malloc
	**line = '\0';
	while((read_s = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\n')
			return (1);
		if (read_s == -1)
		{
			if (*line)
				free (*line);
			return (-1);
		}
	*line = ft_strjoin(*line, buffer);
	}
	if (*line)
		free (*line);
	return (0);
}

int main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
}
