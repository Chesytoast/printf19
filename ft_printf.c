/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:59:42 by mcourtin          #+#    #+#             */
/*   Updated: 2022/11/01 18:21:03 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_which_case(const char *format, int i, va_list list)
{
	char	*uhexa;
	char	*lhexa;

	lhexa = "0123456789abcdef";
	uhexa = "0123456789ABCDEF";
	if (format[i] == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (format[i] == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (format[i] == 'd' || format[i] == 'i')
		return (ft_count_nb_deci(va_arg (list, int)));
	if (format[i] == 'u')
		return (ft_count_nb_base(va_arg(list, unsigned int), "0123456789"));
	if (format[i] == 'x')
		return (ft_count_nb_base(va_arg(list, unsigned int), lhexa));
	if (format[i] == 'p')
		return (ft_count_nb_point(va_arg(list, unsigned long int), lhexa));
	if (format[i] == 'X')
		return (ft_count_nb_base(va_arg(list, unsigned int), uhexa));
	if (format[i] == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		c;
	int		verif;

	c = 0;
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		verif = 0;
		if (format[i] == '%')
		{
			verif = ft_check_which_case(format, ++i, list);
			if (verif == -1)
				return (c);
			c += verif;
		}
		else
			c += write(1, &format[i], 1);
		i++;
	}
	va_end(list);
	return (c);
}


