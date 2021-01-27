#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0, j = 0, c = 0, flag = 0;

	if (argc != 3)
	{
		write(1, "\n",1);
		return (0);
	}
	while (argv[1][i])
	{
		j = 0;
		flag = 1;
		c = 0;
		while (argv[2][c])
		{
			if (argv[1][i] == argv[2][c])
				flag = 0;
			c++;
		}
		while (j < i && !flag)
		{
			if (argv[1][j] == argv[1][i])
				flag = 1;
			j++;
		}
		if (!flag)
			write(1, &argv[1][i],1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
