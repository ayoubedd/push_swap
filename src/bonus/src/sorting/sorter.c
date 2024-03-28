/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:25:40 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/03 12:57:16 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	handler(t_node **stack_a, t_node **stack_b, t_instra value)
{
	if (value == SA)
		sa(stack_a);
	if (value == SB)
		sb(stack_b);
	if (value == SS)
		ss(stack_a, stack_b);
	if (value == PA)
		pa(stack_a, stack_b);
	if (value == PB)
		pb(stack_a, stack_b);
	if (value == RA)
		ra(stack_a);
	if (value == RB)
		rb(stack_b);
	if (value == RR)
		rr(stack_a, stack_b);
	if (value == RRA)
		rra(stack_a);
	if (value == RRB)
		rrb(stack_b);
	if (value == RRR)
		rrr(stack_a, stack_b);
}

void	sorter(t_node **stack_a, t_node **stack_b, t_instras *instractions)
{
	t_instras	*tmp;

	tmp = instractions;
	while (tmp)
	{
		handler(stack_a, stack_b, tmp->value);
		tmp = tmp->next;
	}
}
