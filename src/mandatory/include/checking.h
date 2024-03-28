/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:01:02 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/22 22:16:34 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKING_H
# define CHECKING_H

# include "push_swap.h"

t_bool	checker(char *av[]);
t_bool	check_syntax(char *nums[]);
t_bool	check_overflow(char *nums[]);
t_bool	check_sorted(char *nums[]);
t_bool	check_duplicate(char *nums[]);

#endif