/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:53:21 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/07 18:44:42 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_print_ptr(void *ptr)
{
	int					print_length;
	unsigned long long	address;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == NULL)
		print_length += write(1, "0", 1);
	else
	{
		address = (unsigned long long)ptr;
		ft_put_ptr(address);
		print_length += ft_ptr_len(address);
	}
	return (print_length);
}
