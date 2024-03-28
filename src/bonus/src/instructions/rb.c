/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:30:43 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:28:08 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	rb(t_node **stack_b)
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
