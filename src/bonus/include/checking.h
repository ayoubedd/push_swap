/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:15:22 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:14:12 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKING_H
# define CHECKING_H

t_bool	checker(char *av[]);
t_bool	check_syntax(char *nums[]);
t_bool	check_overflow(char *nums[]);
t_bool	check_sorted(char *nums[]);
t_bool	check_duplicate(char *nums[]);
t_bool	sorted_check(t_node **stack_a, int count);

#endif