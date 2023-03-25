/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:42:29 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 14:39:29 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_printf(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_numlen_printf(long long n)
{
	int				i;
	unsigned int	u_n;

	i = 0;
	if (n <= 0)
	{
		u_n = (unsigned int)(-n);
		i = 1;
	}
	else
		u_n = (unsigned int)n;
	while (u_n > 0)
	{
		u_n /= 10;
		i++;
	}
	return (i);
}

void	ft_putstr_printf(char *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen_printf(s);
	write(1, s, len);
}

void	ft_putnbr_printf(long long n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_printf(-n);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

int	ft_putnbr_hex_printf(unsigned long long n, char c)
{
	int			len;
	const char	*upper_hex = "0123456789ABCDEF";
	const char	*lower_hex = "0123456789abcdef";

	len = 0;
	if (n > 15)
		len += ft_putnbr_hex_printf(n / 16, c);
	if (c == 'X')
		write(1, &upper_hex[n % 16], 1);
	else
		write(1, &lower_hex[n % 16], 1);
	len++;
	return (len);
}
