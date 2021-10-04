/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:49:51 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/22 14:35:33 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_kostil(t_print *flags, long long int arg)
{
	if (arg == 0 && flags->accuracy == 0 && flags->point == '.')
		arg = 0;
	else
		ft_putnbr_struct(arg, flags);
}

void	ft_kostil_x(t_print *flags, long long int arg)
{
	if (arg == 0 && flags->accuracy == 0 && flags->point == '.')
		arg = 0;
	else
		ft_putnbr_x_struct(arg, flags);
}

int		ft_count_num(long long int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	if (nb == 0 || nb < 10)
		return ((1 + i));
	else
	{
		while (nb)
		{
			nb = nb / 10;
			i++;
		}
	}
	return (i);
}

int		ft_count_num_x(unsigned long int num)
{
	int i;

	i = 0;
	if (num < 17)
		return (1);
	else
	{
		while (num)
		{
			num = num / 16;
			i++;
		}
	}
	return (i);
}

int		ft_print_u(t_print *flags, va_list argum)
{
	int				i;
	unsigned int	arg;

	arg = va_arg(argum, unsigned int);
	i = flags->len_ret;
	if (flags->accuracy > 0 && flags->accuracy > ft_count_num(arg))
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
