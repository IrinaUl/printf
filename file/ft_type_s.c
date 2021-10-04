/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:48:09 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/21 22:25:36 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_left_or_right(t_print *flags, char *str_arg)
{
	if (flags->flag == '-' || flags->width < 0)
	{
		if (flags->width < 0)
			flags->width = flags->width * -1;
		ft_putstr(str_arg, flags);
		ft_space_c(flags, flags->width, ft_strlen(str_arg), ' ');
	}
	else
	{
		ft_space_c(flags, flags->width, ft_strlen(str_arg), ' ');
		ft_putstr(str_arg, flags);
	}
}

static void	ft_sh_accuracy(t_print *flags, char *str_arg)
{
	int i;

	i = flags->accuracy;
	if (flags->flag == '-' || flags->width < 0)
	{
		if (flags->width < 0)
			flags->width = flags->width * -1;
		while (i--)
		{
			ft_putchar(*str_arg, &(flags->len_ret));
			str_arg++;
		}
		ft_space_c(flags, flags->width, flags->accuracy, ' ');
	}
	else
	{
		ft_space_c(flags, flags->width, flags->accuracy, ' ');
		while (flags->accuracy-- && *str_arg)
		{
			ft_putchar(*str_arg, &(flags->len_ret));
			str_arg++;
		}
	}
}

int			ft_print_s(t_print *flags, va_list argum)
{
	char *str_arg;

	str_arg = va_arg(argum, char *);
	if (!str_arg)
		str_arg = "(null)";
	if (str_arg)
	{
		if (flags->point == '.')
		{
			if (flags->accuracy >= ft_strlen(str_arg) || flags->accuracy < 0)
				ft_left_or_right(flags, str_arg);
			else if ((0 < flags->accuracy) &&
			(flags->accuracy < ft_strlen(str_arg)))
				ft_sh_accuracy(flags, str_arg);
			else
				ft_space_c(flags, flags->width, 0, ' ');
		}
		else
			ft_left_or_right(flags, str_arg);
	}
	else
		ft_space_c(flags, flags->width, 1, ' ');
	return (1);
}
