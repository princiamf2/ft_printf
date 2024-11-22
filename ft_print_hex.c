/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:20:19 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/08 13:19:25 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned int num, const char format)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += put_hex(num / 16, format);
		i += put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			i += ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				i += ft_putchar(num - 10 + 'a');
			if (format == 'X')
				i += ft_putchar(num - 10 + 'A');
		}
	}
	return (i);
}

int	printf_hex(unsigned int num, const char format)
{
	int	i;

	i = 0;
	if (num == 0)
		i += write(1, "0", 1);
	else
		i += put_hex(num, format);
	return (i);
}
