/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:39:35 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/22 18:15:01 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_space_c(t_print *flags, int count, int min, char c)
{
	int i;

	i = count;
	if (i < 0)
		i *= -1;
	while (i > min)
	{
		ft_putchar(c, &(flags->len_ret));
		i--;
	}
}

int		ft_print_c(t_print *flags, va_list argum)
{
	if (flags->flag == '-' || flags->width < 0)
	{
		if (flags->width < 0)
			flags->width *= -1;
		if (flags->type == 'c')
			ft_putchar(va_arg(argum, int), &(flags->len_ret));
		else
			ft_putchar('%', &(flags->len_ret));
		ft_space_c(flags, flags->width, 1, ' ');
	}
	else if (flags->flag == '0' && flags->width > 1 && flags->type == '%')
	{
		ft_space_c(flags, flags->width, 1, '0');
		ft_putchar('%', &(flags->len_ret));
	}
	else
	{
		ft_space_c(flags, flags->width, 1, ' ');
		if (flags->type == 'c')
			ft_putchar(va_arg(argum, int), &(flags->len_ret));
		else
			ft_putchar('%', &(flags->len_ret));
	}
	return (1);
}
