#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0, j = 0, flag = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		flag = 0;
		j = 0;
		while (j < i && !flag)
		{
			if (argv[1][i] == argv[1][j])
				flag = 1;
				j++;
		}
		if (!flag)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0, j = 0, flag = 0;
	while (argv[2][i] != '\0')
	{
		flag = 0;
		j = 0;
		while (argv[1][j] != '\0' && !flag)
		{
			if (argv[1][j] == argv[2][i])
				flag = 1;
			j++;
		}
		j = 0;
		while (j < i && !flag)
		{
			if (argv[2][j] == argv[2][i])
				flag = 1;
			j++;
		}
		if (!flag)
			write(1, &argv[2][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
