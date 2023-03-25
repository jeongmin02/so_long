/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:35:46 by jerhee            #+#    #+#             */
/*   Updated: 2023/03/25 14:42:46 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, va_list ap)
{
	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_printf(str);
	return (ft_strlen_printf(str));
}

int	print_num(char c, va_list ap)
{
	int				num;
	unsigned int	u_num;

	if (c == 'd' || c == 'i')
	{
		num = va_arg(ap, int);
		ft_putnbr_printf(num);
		return (ft_numlen_printf(num));
	}
	else if (c == 'u')
	{
		u_num = va_arg(ap, unsigned int);
		ft_putnbr_printf(u_num);
		return (ft_numlen_printf(u_num));
	}
	return (0);
}

int	print_hex(char c, va_list ap)
{
	unsigned long long	p_hex;
	unsigned int		n_hex;

	if (c == 'p')
	{
		p_hex = va_arg(ap, unsigned long long);
		write(1, "0x", 2);
		return (ft_putnbr_hex_printf(p_hex, 'p') + 2);
	}
	else if (c == 'x' || c == 'X')
	{
		n_hex = va_arg(ap, unsigned int);
		if (c == 'x')
			return (ft_putnbr_hex_printf(n_hex, 'x'));
		else
			return (ft_putnbr_hex_printf(n_hex, 'X'));
	}
	return (0);
}

int	print_percent(char c)
{
	if (c == '%')
		write(1, "%", 1);
	return (1);
}
