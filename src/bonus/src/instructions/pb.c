/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:29:39 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:27:45 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (!tmp)
		return ;
	*stack_a = tmp->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (!*stack_b)
	{
		*stack_b = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
		return ;
	}
	(*stack_b)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
}
