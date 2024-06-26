/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:18:35 by aeddaoud          #+#    #+#             */
/*   Updated: 2021/12/08 13:08:07 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_toupper_pf(int c);
void	ft_putchar_pf(char c, int *count);
void	ft_putstr_pf(char *str, int *count);
void	ft_puthex_pf(unsigned long n, int *count, int mode);
void	ft_putnbr_pf(long n, int *count);

#endif
