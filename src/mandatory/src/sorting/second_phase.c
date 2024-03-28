/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_phase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:32:25 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:36:12 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "instructions.h"

static void	stack_a_empty(t_node **stack_a,
t_node **stack_b, t_instras **list)
{
	if ((*stack_b)->value > (*stack_b)->next->value)
		sb(stack_b, list);
	pa(stack_a, stack_b, list);
}

static void	helpers_out(t_node **stack_a, t_node **stack_b,
t_instras **list)
{
	if ((*stack_b)->value > (*stack_b)->next->value
		&& last_node(*stack_a)->value < (*stack_b)->next->value)
		sb(stack_b, list);
	pa(stack_a, stack_b, list);
	ra(stack_a, list);
}

static void	handle_way(t_push_swap *core, t_node *target)
{
	t_way	way;

	way = which_way(core->stack_b, target);
	if (way == TOP)
		rb(&core->stack_b, &core->instras);
	else
		rrb(&core->stack_b, &core->instras);
}

static void	handle_push(t_push_swap *core, t_node *target, int biggest)
{
	while (TRUE)
	{
		if (!core->stack_a)
		{
			stack_a_empty(&core->stack_a, &core->stack_b, &core->instras);
			continue ;
		}
		if (core->stack_b && core->stack_b->value == target->value)
		{
			pa(&core->stack_a, &core->stack_b, &core->instras);
			break ;
		}
		if (check_num_in_stack(core->stack_a, target->value))
		{
			rra(&core->stack_a, &core->instras);
			break ;
		}
		if ((last_node(core->stack_a)->value == biggest)
			|| (core->stack_b->value > last_node(core->stack_a)->value))
		{
			helpers_out(&core->stack_a, &core->stack_b, &core->instras);
			continue ;
		}
		handle_way(core, target);
	}
}

void	second_phase(t_push_swap *core)
{
	int		biggest;
	t_node	*sorted;

	sorted = core->sorted;
	while (sorted->next)
		sorted = sorted->next;
	biggest = sorted->value;
	while (sorted)
	{
		handle_push(core, sorted, biggest);
		sorted = sorted->prev;
	}
}
