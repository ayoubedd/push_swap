/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:05:12 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/28 10:29:07 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_node	**head, t_node *node);

t_node	*copy_stack(t_node *stack)
{
	t_node	*head;
	t_node	*index;
	t_node	*tmp;

	head = NULL;
	index = stack;
	while (index)
	{
		tmp = malloc(sizeof(t_node));
		if (!tmp)
			return (NULL);
		tmp->prev = NULL;
		tmp->value = index->value;
		tmp->next = NULL;
		add_back(&head, tmp);
		index = index->next;
	}
	return (head);
}

int	nums_count(t_node *nums)
{
	int	count;

	count = 0;
	while (nums)
	{
		nums = nums->next;
		count++;
	}
	return (count);
}

t_node	*get_node_by_idx(t_node *list, size_t idx)
{
	while (list && idx != 0)
	{
		list = list->next;
		idx--;
	}
	return (list);
}

t_chunk	*last_chunk(t_chunk *chunks)
{
	if (!chunks)
		return (NULL);
	while (chunks->next)
		chunks = chunks->next;
	return (chunks);
}

t_bool	check_num_in_stack(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}
