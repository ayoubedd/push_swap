/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:46:35 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/03 11:11:17 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "sorting.h"

static void	mode_3(t_push_swap *core)
{
	case_one(&core->stack_a, &core->instras);
	case_two(&core->stack_a, &core->instras);
	case_three(&core->stack_a, &core->instras);
	case_four(&core->stack_a, &core->instras);
	case_five(&core->stack_a, &core->instras);
}

static void	mode_5(t_push_swap *core)
{
	t_instras	**list;
	t_node		**stack_a;
	t_node		**stack_b;

	list = &core->instras;
	stack_a = &core->stack_a;
	stack_b = &core->stack_b;
	if (nums_count(*stack_a) == 4)
		push_first_n_nums(core, 1);
	else if (nums_count(*stack_a) == 5)
		push_first_n_nums(core, 2);
	mode_3(core);
	while (*stack_b)
		pa(stack_a, stack_b, list);
}

static void	mode_2(t_push_swap *core)
{
	sa(&core->stack_a, &core->instras);
}

void	small_numbers(t_push_swap *core, enum e_mode mode)
{
	if (mode == MODE_2)
		mode_2(core);
	if (mode == MODE_3)
		mode_3(core);
	if (mode == MODE_5)
		mode_5(core);
}
