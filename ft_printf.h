/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:06:46 by mcourtin          #+#    #+#             */
/*   Updated: 2022/11/01 13:29:19 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putnbr_base(unsigned int n, char *base);
int		ft_check_which_case(const char *format, int i, va_list list);
int		ft_printf(const char *format, ...);
int		ft_count_nb_deci(int n);
int		ft_count_nb_base(unsigned int n, char *base);
int		ft_count_nb_point(unsigned long int n, char *base);
void	ft_putnbr_point(unsigned long int n, char *base);

#endif