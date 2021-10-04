/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacie <mkacie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:22:36 by mkacie            #+#    #+#             */
/*   Updated: 2021/01/22 22:55:03 by mkacie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_printf
{
	char		minus;
	char		flag;
	int			width;
	char		point;
	int			accuracy;
	char		type;
	int			len_ret;
}				t_print;

void			ft_putchar(char c, int *len_ret);
void			ft_putstr(char *str, t_print *flags);
int				ft_type(char c);
void			ft_nullstruct(t_print *flags);
int				ft_star_or_num(const char *str_f, int *pole,
								va_list argum, int inx);
int				ft_isdigit(int c);
int				ft_strlen(const char *str);
void			ft_space_c(t_print *flags, int count, int min, char c);
void			ft_putnbr_struct(long long int nb, t_print *flags);
void			ft_putnbr_x_struct(unsigned int num, t_print *flags);
int				ft_count_num(long long int nb);
int				ft_count_num_x(unsigned long int num);
void			ft_kostil(t_print *flags, long long int arg);
void			ft_kostil_x(t_print *flags, long long int arg);
void			ft_acur_net(t_print *flags, long long int arg, int i);
void			ft_acur_right(t_print *flags, long long int arg);
void			ft_v_number(t_print *flags, long long int arg,
							char c, int chek);
void			ft_min_accur(t_print *flags, long long int arg);
int				ft_printf(const char *format, ...);
int				ft_parser(const char *str_f, t_print *flags,
							va_list argum, int inx);
int				ft_printer(t_print *flags, va_list argum);
int				ft_print_c(t_print *flags, va_list argum);
int				ft_print_s(t_print *flags, va_list argum);
int				ft_print_id(t_print *flags, va_list argum);
int				ft_print_p(t_print *flags, va_list argum);
int				ft_print_u(t_print *flags, va_list argum);
int				ft_print_x(t_print *flags, va_list argum);
#endif
