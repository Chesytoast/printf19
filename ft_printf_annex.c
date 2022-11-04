/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:05:44 by mcourtin          #+#    #+#             */
/*   Updated: 2022/10/31 13:45:34 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	c;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	c = 0;
	while (s[c])
		c++;
	write(1, s, c);
	return (c);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	ft_putnbr_base(unsigned int n, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (n >= 0 && n < i)
		write(1, &base[n], 1);
	else if (n >= i)
	{
		ft_putnbr_base(n / i, base);
		ft_putnbr_base(n % i, base);
	}
}

void	ft_putnbr_point(unsigned long int n, char *base)
{
	unsigned long int	i;

	i = 0;
	while (base[i])
		i++;
	if (n >= 0 && n < i)
		write(1, &base[n], 1);
	else if (n >= i)
	{
		ft_putnbr_point(n / i, base);
		ft_putnbr_point(n % i, base);
	}
}
