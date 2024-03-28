/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:31:49 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:28:14 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	rra(t_node **stack_a)
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
