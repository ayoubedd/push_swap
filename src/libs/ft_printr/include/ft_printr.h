/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:18:35 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/28 10:40:13 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTR_H
# define FT_PRINTR_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printr(const char *format, ...);
int		ft_toupper_pr(int c);
void	ft_putchar_pr(char c, int *count);
void	ft_putstr_pr(char *str, int *count);
void	ft_puthex_pr(unsigned long n, int *count, int mode);
void	ft_putnbr_pr(long n, int *count);

#endif
