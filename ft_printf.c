/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:55:24 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/08 13:05:10 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printperc(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int		i;
	char	*str;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			i += ft_putstr("(null)");
		else
			i += ft_putstr(str);
	}
	else if (format == 'i' || format == 'd')
		i += ft_putnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		i += printf_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		i += ft_print_ptr(va_arg(args, void *));
	else if (format == 'u')
		i += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == '%')
		i += printperc();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
