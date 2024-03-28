/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_phase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:54:10 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 15:00:00 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "instructions.h"

t_bool	check_nums_in_stack(t_node *stack, t_chunk *chunk)
{
	while (stack)
	{
		if (stack->value >= chunk->start && stack->value <= chunk->end)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

static int	get_median(t_node *stack)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	i /= 2;
	while (stack && i > 0)
	{
		stack = stack->next;
		i--;
	}
	if (stack)
		return (stack->value);
	return (0);
}

void	first_phase(t_push_swap *core)
{
	int		median;
	t_chunk	*chunks;
	t_node	**stack_a;
	t_node	**stack_b;

	median = get_median(core->sorted);
	chunks = core->chunks;
	stack_a = &core->stack_a;
	stack_b = &core->stack_b;
	while (chunks)
	{
		while (TRUE)
		{
			if (!check_nums_in_stack(*stack_a, chunks))
				break ;
			while (!((*stack_a)->value >= chunks->start
					&& (*stack_a)->value <= chunks->end))
				ra(stack_a, &core->instras);
			pb(stack_a, stack_b, &core->instras);
			if ((*stack_b)->value <= median)
				rb(stack_b, &core->instras);
		}
		chunks = chunks->next;
	}
}
