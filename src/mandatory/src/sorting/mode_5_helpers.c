/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_5_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:17:43 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/02 08:14:07 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "instructions.h"

static void	handle_push(t_push_swap *core, t_way way, t_node *target)
{
	t_node		**stack_a;
	t_node		**stack_b;
	t_instras	**list;

	list = &core->instras;
	stack_a = &core->stack_a;
	stack_b = &core->stack_b;
	if (way == TOP)
	{
		while ((*stack_a)->value != target->value)
			ra(stack_a, list);
		pb(stack_a, stack_b, list);
	}
	else
	{
		while ((*stack_a)->value != target->value)
			rra(stack_a, list);
		pb(stack_a, stack_b, list);
	}
}

void	push_first_n_nums(t_push_swap *core, size_t	n)
{
	size_t	i;
	t_way	way;
	t_node	*tmp;
	t_node	*sorted;

	i = 0;
	sorted = sort_numbers(*&core->stack_a);
	if (!sorted)
		return ;
	tmp = sorted;
	while (i < n)
	{
		way = which_way(*&core->stack_a, tmp);
		handle_push(core, way, tmp);
		tmp = tmp->next;
		i++;
	}
	while (sorted)
	{
		tmp = sorted->next;
		free(sorted);
		sorted = tmp;
	}
}
