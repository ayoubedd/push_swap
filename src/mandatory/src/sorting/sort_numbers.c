/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:43:03 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/27 12:13:00 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

static void	bubble_sort(t_node *stack)
{
	t_node	*tmp;
	t_node	*helper;
	int		value_tmp;

	tmp = stack;
	while (tmp)
	{
		helper = tmp;
		while (helper)
		{
			if (tmp->value > helper->value)
			{
				value_tmp = helper->value;
				helper->value = tmp->value;
				tmp->value = value_tmp;
			}
			helper = helper->next;
		}
		tmp = tmp->next;
	}
}

t_node	*sort_numbers(t_node *stack)
{
	t_node	*sorted;

	sorted = NULL;
	if (!stack)
		return (NULL);
	sorted = copy_stack(stack);
	bubble_sort(sorted);
	return (sorted);
}
