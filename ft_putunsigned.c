/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:53:52 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/08 13:00:02 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_putunsigned(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}
