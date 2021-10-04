/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:28:11 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/22 19:33:00 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_min_accur(t_print *flags, long long int arg)
{
	int		i;

	i = flags->len_ret;
	if (arg < 0)
	{
		ft_putchar('-', &(flags->len_ret));
		arg *= -1;
		ft_space_c(flags, flags->accuracy, ft_count_num(arg), '0');
		ft_putnbr_struct(arg, flags);
		i = flags->len_ret - i;
		ft_space_c(flags, flags->width, i, ' ');
	}
	else
	{
		ft_space_c(flags, flags->accuracy, ft_count_num(arg), '0');
		ft_putnbr_struct(arg, flags);
		i = flags->len_ret - i;
		ft_space_c(flags, flags->width, i, ' ');
	}
}

void	ft_v_number(t_print *flags, long long int arg, char c, int chek)
{
	while (chek-- > ft_count_num(arg))
		ft_putchar(c, &(flags->len_ret));
	if (arg == 0 && flags->accuracy == 0 &&
	flags->width != 0 && flags->point == '.')
		ft_putchar(' ', &(flags->len_ret));
	ft_kostil(flags, arg);
}

void	ft_acur_right(t_print *flags, long long int arg)
{
	if (arg < 0)
	{
		ft_space_c(flags, flags->width, (flags->accuracy + 1), ' ');
		ft_putchar('-', &(flags->len_ret));
	}
	else
		ft_space_c(flags, flags->width, flags->accuracy, ' ');
	if (arg < 0)
	{
		arg *= -1;
		ft_space_c(flags, flags->accuracy, ft_count_num(arg), '0');
		if (arg == 0 && flags->accuracy == 0 &&
		flags->width != 0 && flags->point == '.')
			ft_putchar(' ', &(flags->len_ret));
		ft_kostil(flags, arg);
	}
	else
		ft_v_number(flags, arg, '0', flags->accuracy);
}

void	ft_acur_net(t_print *flags, long long int arg, int i)
{
	if (flags->flag == '-' || flags->width < 0)
	{
		if (flags->width < 0)
			flags->width = flags->width * -1;
		ft_kostil(flags, arg);
		i = flags->len_ret - i;
		ft_space_c(flags, flags->width, i, ' ');
	}
	else if ((flags->flag == '0' && flags->width >= 0 && flags->point == '0') ||
	(flags->flag == '0' && flags->width >= 0 && flags->accuracy < 0))
	{
		if (arg < 0)
		{
			ft_putchar('-', &(flags->len_ret));
			arg *= -1;
			ft_space_c(flags, flags->width, (ft_count_num(arg) + 1), '0');
			ft_putnbr_struct(arg, flags);
		}
		else
			ft_v_number(flags, arg, '0', flags->width);
	}
	else
		ft_v_number(flags, arg, ' ', flags->width);
}

int		ft_print_id(t_print *flags, va_list argum)
{
	int				i;
	long long int	arg;
	int				fl_min;

	arg = va_arg(argum, int);
	i = flags->len_ret;
	if (arg < 0)
		fl_min = (ft_count_num(arg) - 1);
	else
		fl_min = ft_count_num(arg);
	if (flags->accuracy > 0 && flags->accuracy > fl_min)
	{
		if (flags->flag == '-' || flags->width < 0)
			ft_min_accur(flags, arg);
		else
			ft_acur_right(flags, arg);
	}
	else
		ft_acur_net(flags, arg, i);
	return (1);
}
