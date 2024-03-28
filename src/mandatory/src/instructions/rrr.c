/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:54:02 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:12:47 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	s_rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*tmp;

	tmp = *stack_a;
	if (!tmp || !tmp->next)
		return ;
	last = last_node(*stack_a);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	*stack_a = last;
}

static void	s_rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*tmp;

	tmp = *stack_b;
	if (!tmp || !tmp->next)
		return ;
	last = last_node(*stack_b);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	*stack_b = last;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_instras **list)
{
	s_rra(stack_a);
	s_rrb(stack_b);
	log_instraction(list, RRR);
}
