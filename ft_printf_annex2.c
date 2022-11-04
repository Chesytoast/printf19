/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:02:13 by mcourtin          #+#    #+#             */
/*   Updated: 2022/11/01 13:29:12 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_nb_deci(int n)
{
	int			c;
	long int	nb;

	nb = n;
	ft_putnbr(n);
	if (n == 0)
		return (1);
	c = 0;
	if (nb < 0)
		c++;
	while (nb)
	{
		c++;
		nb = nb / 10;
	}
	return (c);
}

int	ft_count_nb_base(unsigned int n, char *base)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (base[i])
		i++;
	ft_putnbr_base(n, base);
	if (n == 0)
		return (1);
	while (n)
	{
		c++;
		n = n / i;
	}
	return (c);
}

int	ft_count_nb_point(unsigned long int n, char *base)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (base[i])
		i++;
	c += write(1, "0x", 2);
	ft_putnbr_point(n, base);
	if (n == 0)
		return (3);
	while (n)
	{
		c++;
		n = n / i;
	}
	return (c);
}
