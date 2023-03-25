/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:22:35 by jerhee            #+#    #+#             */
/*   Updated: 2022/08/22 18:41:25 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(c, ap);
	else if (c == 's')
		len += print_string(ap);
	else if (c == 'd' || c == 'i' || c == 'u')
		len += print_num(c, ap);
	else if (c == 'p' || c == 'x' || c == 'X')
		len += print_hex(c, ap);
	else if (c == '%')
		len += print_percent(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += check_type(format[i + 1], ap);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
