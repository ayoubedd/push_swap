/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:16:05 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/28 10:41:02 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printr.h"

int	ft_toupper_pr(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	ft_putchar_pr(char c, int *count)
{
	write(STDERR_FILENO, &c, 1);
	(*count)++;
}

void	ft_puthex_pr(unsigned long n, int *count, int mode)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		ft_puthex_pr(n / 16, count, mode);
	if (mode)
		ft_putchar_pr(ft_toupper_pr(hex[n % 16]), count);
	else
		ft_putchar_pr(hex[n % 16], count);
}

void	ft_putstr_pr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_pr("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar_pr(str[i], count);
		i++;
	}
}

void	ft_putnbr_pr(long n, int *count)
{
	if (n < 0)
	{
		ft_putchar_pr('-', count);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_pr(n / 10, count);
	ft_putchar_pr(n % 10 + '0', count);
}
