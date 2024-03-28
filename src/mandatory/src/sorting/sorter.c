/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:32:29 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/03 12:52:23 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"
#include "instructions.h"
#include "config.h"

void	get_mode(int ac, t_mode *mode)
{
	if (ac > 150)
	{
		mode->mode = MODE_500;
		mode->chunk_size = 32;
	}
	if (ac <= 150)
	{
		mode->mode = MODE_100;
		mode->chunk_size = 18;
	}
	if (ac <= 5)
		mode->mode = MODE_5;
	if (ac <= 3)
		mode->mode = MODE_3;
	if (ac <= 2)
		mode->mode = MODE_2;
}

void	sorter(t_push_swap *core)
{
	t_mode	mode;

	core->sorted = sort_numbers(core->stack_a);
	get_mode(core->ac, &mode);
	core->chunks = build_chunks(core->sorted, &mode);
	if (mode.mode == MODE_3 || mode.mode == MODE_5 || mode.mode == MODE_2)
		small_numbers(core, mode.mode);
	if (mode.mode == MODE_100 || mode.mode == MODE_500)
	{
		first_phase(core);
		second_phase(core);
	}
}
