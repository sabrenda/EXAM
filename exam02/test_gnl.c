#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char s2)
{
	int i = 0;
	char *str = NULL;
	str = (char *)malloc(ft_strlen(s1) + 2);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = s2;
	str[i] = '\0';
	free (s1);
	s1 = NULL;
	return (str);
}

int get_next_line(char **line)
{
	char buffer;
	int read_s;
	*line = (char *)malloc(1);
	**line = '\0';

	while ((read_s = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\n')
			return (1);
		*line = ft_strjoin(*line, buffer);
	}
	if (read_s == -1)
	{
		if (*line)
			free (*line);
		return (-1);
	}
	return (0);
}

int main()
{
	int i = 0, j = 0;
	char *line = NULL;

	while ((j = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free (line);
	}
	printf("%s\n", line);
	free (line);
	return 0;
}
