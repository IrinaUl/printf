/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:19:57 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/22 22:48:53 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_clean(t_print *flags)
{
	flags->minus = '0';
	flags->flag = '1';
	flags->width = 0;
	flags->point = '0';
	flags->accuracy = 0;
	flags->type = 0;
}

int			ft_printer(t_print *flags, va_list argum)
{
	int	error;

	error = 1;
	if (flags->type == 'i' || flags->type == 'd')
		error = ft_print_id(flags, argum);
	if (flags->type == 'x' || flags->type == 'X')
		error = ft_print_x(flags, argum);
	if (flags->type == 'u')
		error = ft_print_u(flags, argum);
	if (flags->type == 'c' || flags->type == '%')
		error = ft_print_c(flags, argum);
	if (flags->type == 's')
		error = ft_print_s(flags, argum);
	if (flags->type == 'p')
		error = ft_print_p(flags, argum);
	return (error);
}

int			ft_parser(const char *str_f, t_print *flags, va_list argum, int inx)
{
	while (str_f[inx] == '0' || str_f[inx] == '-')
	{
		if (str_f[inx] == '-')
			flags->minus = '-';
		flags->flag = str_f[inx];
		if (flags->minus == '-')
			flags->flag = '-';
		inx++;
	}
	inx = ft_star_or_num(str_f, &(flags->width), argum, inx);
	if (str_f[inx] == '.')
	{
		flags->point = '.';
		inx++;
		inx = ft_star_or_num(str_f, &(flags->accuracy), argum, inx);
	}
	if (ft_type(str_f[inx]) == 1)
		flags->type = str_f[inx];
	else
		return (-1);
	if (ft_printer(flags, argum) == -1)
		return (-1);
	return (inx);
}

static int	ft_specif(const char *str_f, t_print *flags, va_list argum, int inx)
{
	while (str_f[inx] != '\0')
	{
		if (str_f[inx] == '%')
		{
			inx++;
			if (str_f[inx] == '\0')
				break ;
			else
			{
				if ((inx = ft_parser(str_f, flags, argum, inx)) == -1)
					break ;
				ft_clean(flags);
			}
		}
		else
			ft_putchar(str_f[inx], &(flags->len_ret));
		inx++;
	}
	return (inx);
}

int			ft_printf(const char *str_f, ...)
{
	t_print	flags;
	va_list	argum;
	int		inx;

	inx = 0;
	if ((!str_f) || (!*str_f))
		return (-1);
	ft_nullstruct(&flags);
	va_start(argum, str_f);
	inx = ft_specif(str_f, &flags, argum, inx);
	va_end(argum);
	return (inx == -1 ? -1 : flags.len_ret);
}
