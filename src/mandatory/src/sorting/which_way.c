/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:19:55 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/27 12:22:19 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

t_way	which_way(t_node *stack, t_node *node)
{
	int	i;
	int	stack_mid;

	i = 0;
	stack_mid = nums_count(stack) / 2 - 1;
	while (stack)
	{
		if (stack->value == node->value)
			break ;
		stack = stack->next;
		i++;
	}
	if (i <= stack_mid)
		return (TOP);
	else
		return (BOTTOM);
}
