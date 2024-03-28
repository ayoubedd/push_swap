/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:27:59 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:36:12 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"

void	sb(t_node **stack_b, t_instras **list)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack_b;
	third = NULL;
	if (!first || !first->next)
		return ;
	second = first->next;
	third = second->next;
	if (third)
		third->prev = first;
	second->prev = NULL;
	second->next = first;
	first->next = third;
	first->prev = second;
	*stack_b = second;
	log_instraction(list, SB);
}
