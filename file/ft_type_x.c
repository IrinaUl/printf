/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:41:48 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/22 19:33:31 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_min_accur_x(t_print *flags, unsigned int arg)
{
	int		i;

	i = flags->len_ret;
	if (arg < 0)
	{
		ft_putchar('-', &(flags->len_ret));
		arg *= -1;
		ft_space_c(flags, flags->accuracy, ft_count_num_x(arg), '0');
		ft_putnbr_x_struct(arg, flags);
		i = flags->len_ret - i;
		ft_space_c(flags, flags->width, i, ' ');
	}
	else
	{
		ft_space_c(flags, flags->accuracy, ft_count_num_x(arg), '0');
		ft_putnbr_x_struct(arg, flags);
		i = flags->len_ret - i;
		ft_space_c(flags, flags->width, i, ' ');
	}
}

static void	ft_v_number_x(t_print *flags, unsigned int arg, char c, int chek)
{
	while (chek-- > ft_count_num_x(arg))
		ft_putchar(c, &(flags->len_ret));
	if (arg == 0 && flags->accuracy == 0 &&
	flags->width != 0 && flags->point == '.')
		ft_putchar(' ', &(flags->len_ret));
	ft_kostil_x(flags, arg);
}

static void	ft_acur_right_x(t_print *flags, unsigned int arg)
{
	if (arg < 0)
	{
		ft_space_c(flags, flags->width, (flags->accuracy + 1), ' ');
		ft_putchar('-', &(flags->len_ret));
		arg *= -1;
	}
	else
		ft_space_c(flags, flags->width, flags->accuracy, ' ');
	ft_v_number_x(flags, arg, '0', flags->accuracy);
}

static void	ft_acur_net_x(t_print *flags, unsigned int arg, int i)
{
	if (flags->flag == '-' || flags->width < 0)
	{
		if (flags->width < 0)
			flags->width = flags->width * -1;
		ft_kostil_x(flags, arg);
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
			ft_space_c(flags, flags->width, (ft_count_num_x(arg) + 1), '0');
			ft_putnbr_x_struct(arg, flags);
		}
		else
			ft_v_number_x(flags, arg, '0', flags->width);
	}
	else
		ft_v_number_x(flags, arg, ' ', flags->width);
}

int			ft_print_x(t_print *flags, va_list argum)
{
	int				i;
	unsigned int	arg;

	arg = va_arg(argum, unsigned int);
	i = flags->len_ret;
	if (flags->accuracy > 0 && flags->accuracy > ft_count_num_x(arg))
	{
		if (flags->flag == '-' || flags->width < 0)
			ft_min_accur_x(flags, arg);
		else
			ft_acur_right_x(flags, arg);
	}
	else
		ft_acur_net_x(flags, arg, i);
	return (1);
}
