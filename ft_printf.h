/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:52:28 by mm-furi           #+#    #+#             */
/*   Updated: 2024/10/08 13:20:25 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		len_hex(unsigned int num);
int		ft_putunsigned(unsigned int nb);
int		printf_hex(unsigned int num, const char format);
int		ft_ptr_len(unsigned long long num);
int		ft_print_ptr(void *ptr);
int		ft_printperc(void);
int		ft_formats(va_list args, const char format);
int		ft_printf(const char *str, ...);
void	ft_put_ptr(unsigned long long num);
int		put_hex(unsigned int num, const char format);
#endif
