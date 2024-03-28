/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:32:08 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:36:12 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	rrb(t_node **stack_b, t_instras **list)
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
	log_instraction(list, RRB);
}
