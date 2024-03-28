/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:29:22 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:27:40 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_b;
	if (!tmp)
		return ;
	*stack_b = tmp->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (!*stack_a)
	{
		*stack_a = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
		return ;
	}
	(*stack_a)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
}
