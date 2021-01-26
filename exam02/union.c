/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:01:36 by sabrenda          #+#    #+#             */
/*   Updated: 2021/01/26 23:01:29 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0, c = 0, flag = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		c = 0;
		flag = 0;
		while (c < i && !flag)
		{
			if (argv[1][c] == argv[1][i])
				flag = 1;
			c++;
		}
		if (!flag)
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0, c = 0, flag = 0;
	while (argv[2][i])
	{
		c = 0;
		flag = 0;
		while (argv[1][c] != '\0' && !flag)
		{
			if (argv[1][c] == argv[2][i])
				flag = 1;
			c++;
		}
		c = 0;
		while (c < i && !flag)
		{
			if (argv[2][c] == argv[2][i])
				flag = 1;
			c++;
		}
		if (!flag)
			write(1, &argv[2][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
