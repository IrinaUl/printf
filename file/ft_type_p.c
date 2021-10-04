/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:39:35 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/23 16:04:17 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_putnbr_p_struct(unsigned long long int num, t_print *flags)
{
	if (num >= 16)
	{
		ft_putnbr_p_struct((num / 16), flags);
		if ((num % 16) < 10)
			ft_putchar(num % 16 + '0', &(flags->len_ret));
		else
			ft_putchar(num % 16 + 'W', &(flags->len_ret));
	}
	else
	{
		if ((num % 16) < 10)
			ft_putchar(num + '0', &(flags->len_ret));
		else
			ft_putchar(num % 16 + 'W', &(flags->len_ret));
	}
}

static void		kostil_for_p(unsigned long long int num, t_print *flags)
{
	if (flags->point == '.' && flags->accuracy == 0)
		num = 0;
	else
		ft_putnbr_p_struct(num, flags);
}

static void		kostil_for_ac(t_print *flags, int len_num)
{
	if (flags->point == '.' && flags->accuracy == 0)
		ft_space_c(flags, flags->width, (len_num + 1), ' ');
	else
		ft_space_c(flags, flags->width, (len_num + 2), ' ');
}

int				ft_print_p(t_print *flags, va_list argum)
{
	char					*str_arg;
	unsigned long long int	p;
	int						len_num;

	str_arg = "0x";
	p = va_arg(argum, unsigned long long int);
	len_num = ft_count_num_x(p);
	if (flags->flag == '-' || flags->width < 0)
	{
		if (flags->width < 0)
			flags->width *= -1;
		ft_putstr(str_arg, flags);
		kostil_for_p(p, flags);
		kostil_for_ac(flags, len_num);
	}
	else
	{
		kostil_for_ac(flags, len_num);
		ft_putstr(str_arg, flags);
		kostil_for_p(p, flags);
	}
	return (1);
}
