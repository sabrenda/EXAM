typedef struct		s_flag
{
	int				width;
	int				dot;
	int				flag_on;
	int				d_flag_on;
	int				t_flag_on;
	int				type_len_x;
	int				add;
	int				dota;
	int				minus_add;
	char			*type_s;
	int				type_i;
	unsigned int	type_x;
}					t_f;

int		ft_parser(const char **str, va_list ap)
{
	t_f		t_flag;
	int 	count = 0;

	ft_init_flags(&t_flag);
	ft_init_type(&t_flag);
	while (**str != '\0')
	{
		if ((**str == '*' || ft_isdigit(str)) && !t_flag.d_flag_on)
			ft_width(str, ap, &t_flag);
		else if (**str == '.')
			ft_dot(str, ap, &t_flag);
		if (ft_strchr("sdx", **str))
		{
			if (**str == 's')
				count += ft_build_s(ap, t_flag);
			if (**str == 'd')
				count += ft_build_i(ap, t_flag);
			if (**str == 'x')
				count += ft_build_x(**str, ap, t_flag);
			return (count);
		}
		if (**str == '\0')
			break ;
		(*str)++;
	}
	return (ft_type(str, ap, &t_flag, count_n));
}

int		ft_work_printf(const char **str, va_list ap)
{
	int		count;

	count = 0;
	while (1)
	{
		if (**str == '%')
		{
			(*str)++;
			if (**str == '\0')
				return (count);
			count += ft_parser(str, ap, count);
			if (**str == '\0')
				return (count);
			(*str)++;
		}
		if (**str == '\0')
			break ;
		if (**str == '%')
			continue;
		write(1, *str, 1);
		(*str)++;
		count++;
	}
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int				count_printf;
	va_list			ap;

	count_printf = 0;
	va_start(ap, str);
	count_printf += ft_work_printf(&str, ap);
	va_end(ap);
	return (count_printf);
}
