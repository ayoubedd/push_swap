/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:00:12 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:36:12 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

static void	s_ra(t_node **stack_a)
{
	t_node	*last;
	t_node	*tmp;

	tmp = *stack_a;
	if (!tmp || !tmp->next)
		return ;
	tmp->next->prev = NULL;
	*stack_a = tmp->next;
	last = last_node(*stack_a);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

static void	s_rb(t_node **stack_b)
{
	t_node	*last;
	t_node	*tmp;

	tmp = *stack_b;
	if (!tmp || !tmp->next)
		return ;
	tmp->next->prev = NULL;
	*stack_b = tmp->next;
	last = last_node(*stack_b);
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	rr(t_node **stack_a, t_node **stack_b, t_instras **list)
{
	s_ra(stack_a);
	s_rb(stack_b);
	log_instraction(list, RR);
}
