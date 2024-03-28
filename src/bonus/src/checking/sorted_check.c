/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:42:01 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:13:57 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	check_count(t_node **stack_a, int count)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i != count)
		return (TRUE);
	return (FALSE);
}

static t_bool	check_sorted(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->prev)
			if (tmp->prev->value > tmp->value)
				return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

t_bool	sorted_check(t_node **stack_a, int count)
{
	if (check_count(stack_a, count) || check_sorted(stack_a))
		return (TRUE);
	return (FALSE);
}
