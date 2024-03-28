/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_3_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:56:11 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:36:12 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	case_one(t_node **stack_a, t_instras **list)
{
	t_node	*top;
	t_node	*mid;
	t_node	*last;

	top = *stack_a;
	mid = top->next;
	last = mid->next;
	if (mid->value < top->value && mid->value < last->value
		&& top->value < last->value)
		if (last->value > top->value)
			sa(stack_a, list);
}

void	case_two(t_node **stack_a, t_instras **list)
{
	t_node	*top;
	t_node	*mid;
	t_node	*last;

	top = *stack_a;
	mid = top->next;
	last = mid->next;
	if (top->value > mid->value && mid->value > last->value)
	{
		sa(stack_a, list);
		rra(stack_a, list);
	}
}

void	case_three(t_node **stack_a, t_instras **list)
{
	t_node	*top;
	t_node	*mid;
	t_node	*last;

	top = *stack_a;
	mid = top->next;
	last = mid->next;
	if (top->value > mid->value && top->value > last->value
		&& mid->value < last->value)
		ra(stack_a, list);
}

void	case_four(t_node **stack_a, t_instras **list)
{
	t_node	*top;
	t_node	*mid;
	t_node	*last;

	top = *stack_a;
	mid = top->next;
	last = mid->next;
	if (top->value < mid->value && mid->value > last->value
		&& top->value < last->value)
	{
		sa(stack_a, list);
		ra(stack_a, list);
	}
}

void	case_five(t_node **stack_a, t_instras **list)
{
	t_node	*top;
	t_node	*mid;
	t_node	*last;

	top = *stack_a;
	mid = top->next;
	last = mid->next;
	if (top->value < mid->value && mid->value > last->value
		&& mid->value > top->value)
		rra(stack_a, list);
}
