/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:15:45 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/28 10:36:30 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_process(const char *format, va_list *args, int *count)
{
	if (*format == '%')
		ft_putchar_pf('%', count);
	else if (*format == 'c')
		ft_putchar_pf(va_arg(*args, int), count);
	else if (*format == 's')
		ft_putstr_pf(va_arg(*args, char *), count);
	else if (*format == 'i' || *format == 'd')
		ft_putnbr_pf(va_arg(*args, int), count);
	else if (*format == 'u')
		ft_putnbr_pf(va_arg(*args, unsigned int), count);
	else if (*format == 'p')
	{
		ft_putstr_pf("0x", count);
		ft_puthex_pf(va_arg(*args, size_t), count, 0);
	}
	else if (*format == 'x')
		ft_puthex_pf(va_arg(*args, unsigned int), count, 0);
	else if (*format == 'X')
		ft_puthex_pf(va_arg(*args, unsigned int), count, 1);
	else
		ft_putchar_pf(*format, count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		args;
	int			i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			ft_process(&format[++i], &args, &count);
		else
			ft_putchar_pf(format[i], &count);
		if (format[i] != '\0')
		i++;
	}
	va_end(args);
	return (count);
}
