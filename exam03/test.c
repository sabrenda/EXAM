int rodofat(float x, float y, t_mini *m)
{
	float dist;

	dist = srqt((x - m->x) * (x - m->x) + (y - m->y) * (y - m->y));
	if (dist <= m->radius)
	{
		if(m->radius - dist < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void drowto(t_micro *z, t_zone *zone, char *str)
{
	int x, y;
	int rod;

	while (++y < zone->heigh)
	{
		x = -1;
		while (++x < zone->width)
		{
			rod = rodofat((float)x, (float)y, z)
			if ((z->r == 'c' && rod = 2) ||(z->r == 'C' && rod))
				str[y * zone->width + x] = z->color;
		}
	}
}

int drowing(t_z *zone, FILE *file, char *str)
{
	int i;
	int count;
	t_micro z;

	while ((count = scanf(file, "%c %f %f %f %c\n", &&&&&)) == 5)
	{
		if (!((z->c == 'c' || z->c == 'C') && z->radios > 0.0000000))
			return 0;
		drowtow(&z, zone, str);
	}
	if (count != -1)
		return (0);
	return (1);
}

void lastdrow(char *str, t_zone *zone)
{
	int i = -1;

	while (++i < zone->heigth)
	{
		write(1, str + (zone->width * i), zone->width);
		write(1, "\n", 1);
	}
}

if (dist <= m->radios)
{
	if ( m->radoos - dist < 1.0000000)
		return 2;
	return 1;
}
return 0;
