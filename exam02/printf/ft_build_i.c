void	ft_dot_add_two(t_f *t_flag)
{
	int i;

	if (t_flag->dot == -1)
	{
		t_flag->dota = ft_leni(t_flag->type_i);
		return ;
	}
	if (t_flag->type_i >= 0)
		i = t_flag->dot - ft_leni(t_flag->type_i);
	else
		i = t_flag->dot - (ft_leni(t_flag->type_i) - 1);
	if (i <= 0)
		t_flag->dota = ft_leni(t_flag->type_i);
	else
		t_flag->dota = i + ft_leni(t_flag->type_i);
}

int		ft_dot_add_i(t_f *t_flag)
{
	int i;
	int a;

	a = 0;
	if (t_flag->dot == -1)
		return (0);
	if (t_flag->type_i >= 0)
		i = t_flag->dot - ft_leni(t_flag->type_i);
	else
		i = t_flag->dot - ((ft_leni(t_flag->type_i) - 1));
	if (i <= 0)
		return (0);
	if (!t_flag->minus && t_flag->type_i < 0 && i <= t_flag->width)
		ft_flag_work_i(t_flag);
	if (t_flag->minus && t_flag->type_i < 0)
		ft_flag_work_i(t_flag);
	while (a < i)
	{
		write(1, "0", 1);
		a++;
	}
	if (t_flag->minus_add)
		i++;
	return (i);
}

int		ft_flag_work_i(t_f *t_flag)
{
	if (t_flag->minus_add)
		return (0);
	if (!t_flag->minus_add)
		write(1, "-", 1);
	t_flag->minus_add = 1;
	if (t_flag->dot >= 0 && (t_flag->dot <= ((int)ft_leni(t_flag->type_i) - 1)))
		return (1);
	else if (t_flag->d_flag_on && (t_flag->dot + 1) >= t_flag->width)
		return (0);
	else
		return (1);
}

int		ft_width_flag_work_i(t_f *t_flag, int i)
{
	char	c = ' ';
	int		res;

	res = 0;
	if (t_flag->type_i < 0 && (t_flag->dot + 1) >= t_flag->width)
		res += ft_flag_work_i(t_flag);
	if (t_flag->type_i == 0 && !t_flag->dot && t_flag->width > 0)
		t_flag->width++;
	while (i < t_flag->width)
	{
		write(1, &c, 1);
		i++;
		res++;
	}
	return (res);
}

int		ft_build_i(va_list ap, t_f *t_flag)
{
	int		i;

	i = 0;
	ft_hl_i(ap, t_flag);
	ft_dot_add_two(t_flag);
	if ((t_flag->plus || t_flag->space) && t_flag->zero)
		i += ft_plus_add(t_flag);
	i += ft_width_flag_work_i(t_flag, t_flag->dota + t_flag->add);
	if ((t_flag->plus || t_flag->space) && !t_flag->zero)
		i += ft_plus_add(t_flag);
	i += ft_dot_add_i(t_flag);
	return (i += ft_putin(t_flag));
}
