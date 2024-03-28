/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:27:00 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:28:33 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *stack_a;
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
	*stack_a = second;
}
