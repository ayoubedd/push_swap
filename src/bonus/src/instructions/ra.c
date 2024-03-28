/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:30:09 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:27:57 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	ra(t_node **stack_a)
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
