/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:50:06 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/21 15:18:28 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c, int *len_ret)
{
	*len_ret = *len_ret + (int)write(1, &c, sizeof(char));
}

void	ft_putstr(char *str, t_print *flags)
{
	if (str && *str)
	{
		while (*str)
		{
			ft_putchar(*str, &(flags->len_ret));
			str++;
		}
	}
}

int		ft_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'u' ||
	c == 'p' || c == 's' || c == 'c' || c == '%')
		return (1);
	else
		return (0);
}

void	ft_nullstruct(t_print *flags)
{
	flags->minus = '0';
	flags->flag = '1';
	flags->width = 0;
	flags->point = '0';
	flags->accuracy = 0;
	flags->type = 0;
	flags->len_ret = 0;
}

int		ft_star_or_num(const char *str_f, int *pole, va_list argum, int inx)
{
	if (str_f[inx] == '*' || ft_isdigit(str_f[inx]) == 1)
	{
		while (ft_isdigit(str_f[inx]) == 1)
		{
			*pole = *pole * 10 + str_f[inx] - '0';
			inx++;
		}
		if (str_f[inx] == '*')
		{
			*pole = va_arg(argum, int);
			inx++;
		}
	}
	return (inx);
}
