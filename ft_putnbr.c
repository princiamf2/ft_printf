/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:08:31 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/07 18:45:05 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr > 9)
		i += ft_putnbr(nbr / 10);
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}
