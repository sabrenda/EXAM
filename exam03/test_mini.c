#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_zone
{
	int	WIDTH;
	int	HEIGHT;
	char	BACKGROUND;
}			t_zone;

typedef struct s_micro
{
    char r;
    float x;
    float y;
    float radius;
    char color;
}				t_micro;

void print_draw(char *draw, t_zone *zone)
{
	int i = 0;

	while (i < zone->HEIGHT)
	{
		write(1, draw + (i * zone->WIDTH), zone->WIDTH);
		write(1, "\n", 1);
		i++;
	}
}

int is_rad(float x, float y, t_micro *tmp)
{
    float dist;

    dist = sqrtf(((x - tmp->x) * (x - tmp->x)) + ((y - tmp->y) * (y - tmp->y)));

    if (dist <= tmp->radius)
    {
        if ((tmp->radius - dist) < 1.00000000)
            return (2);
        return (1);
    }
    return (0);
}

void put_to_drow(char *draw, t_micro *m, t_zone *zone)
{
	int x, y, rad;
	float dist;

	y = -1;
	while (++y < zone->HEIGHT)
	{
		x = -1;
		while (++x < zone->HEIGHT)
		{
			rad = is_rad((float)x, (float)y, m);
			if ((m->r == 'c' && rad == 2) || (m->r == 'C' && rad))
				draw[(y * zone->WIDTH) + x] = m->color;
		}
	}
}

int ft_getdrow(t_zone *zone, FILE *file, char *drow)
{
	t_micro	m;
	int count;

	while ((count = fscanf(file, "%c %f %f %f %c\n", &m.r, &m.x, &m.y, &m.radius, &m.color)) == 5)
	{
		if (!((m.radius > 0.00000000) && (m.r == 'c' || m.r == 'C')))
			return (0);
		put_to_drow(drow, &m, zone);
	}
	if (count != -1)
		return (0);
	return (1);
}

char *getzone(t_zone *zone, FILE *file)
{
	int count;
	char *drow;
	int i = -1;
	if ((count = fscanf(file, "%d %d %c\n", &zone->WIDTH, &zone->HEIGHT, &zone->BACKGROUND)) != 3)
		return	NULL;
	if (count == -1)
		return (NULL);
	if (!((0 < zone->WIDTH && zone->WIDTH <= 300) && (0 < zone->HEIGHT && zone->HEIGHT <= 300)))
		return (NULL);
	drow = (char *)malloc(sizeof(char) * (zone->WIDTH * zone->HEIGHT));
	while (++i < zone->WIDTH * zone->HEIGHT) // не забыть!
		drow[i] = zone->BACKGROUND;
	return (drow);
}


int main(int argc, char **argv)
{
	t_zone	zone;
	FILE	*file;
	char	*drowline;

	if (argc != 2)
	{
		printf("Error: argument\n");
		return (1);
	}
	if (!(file = fopen(argv[1], "r"))) // внимание!
	{
		printf("Error: Operation file corrupted\n");
		return (1);
	}
	if (!(drowline = getzone(&zone, file)))
	{
		printf("Error: Operation file corrupted\n");
		fclose (file);
		return (1);
	}
	if (!(ft_getdrow(&zone, file, drowline)))
	{
		printf("Error: Operation file corrupted\n");
		free (drowline);
		fclose (file);
		return (1);
	}
	print_draw(drowline, &zone);
	if (drowline)
		free (drowline);
	fclose (file);
	return (0);
}
