/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:11:59 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/21 14:18:16 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	cap_or_sma(unsigned int num, t_print *flags)
{
	if (flags->type == 'X')
		ft_putchar(num % 16 + '7', &(flags->len_ret));
	else
		ft_putchar(num % 16 + 'W', &(flags->len_ret));
}

int			ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int			ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void		ft_putnbr_struct(long long int nb, t_print *flags)
{
	if (nb < 0)
	{
		ft_putchar('-', &(flags->len_ret));
		nb *= -1;
		ft_putnbr_struct(nb, flags);
	}
	else if (0 <= nb && nb < 10)
	{
		ft_putchar(nb + '0', &(flags->len_ret));
	}
	else if (nb >= 10)
	{
		ft_putnbr_struct(nb / 10, flags);
		ft_putchar(nb % 10 + '0', &(flags->len_ret));
	}
}

void		ft_putnbr_x_struct(unsigned int num, t_print *flags)
{
	if (num >= 16)
	{
		ft_putnbr_x_struct((num / 16), flags);
		if ((num % 16) < 10)
			ft_putchar(num % 16 + '0', &(flags->len_ret));
		else
			cap_or_sma(num, flags);
	}
	else
	{
		if ((num % 16) < 10)
			ft_putchar(num + '0', &(flags->len_ret));
		else
			cap_or_sma(num, flags);
	}
}
