/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrenda <sabrenda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:54:53 by sabrenda          #+#    #+#             */
/*   Updated: 2021/01/26 23:03:02 by sabrenda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0, j = 0, c = 0, flag = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		c = 0;
		flag = 0;
		while (c < i && !flag)
		{
			if (argv[1][c] == argv[1][i])
				flag = 1;
			c++;
		}
		j = 0;
		while (argv[2][j] != '\0' && !flag)
		{
			if (argv[1][i] == argv[2][j])
			{
				write(1, &argv[1][i], 1);
				flag = 1;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
