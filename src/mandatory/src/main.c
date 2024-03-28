/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 05:01:37 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:10:50 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "sorting.h"
#include "checking.h"
#include "optimizing.h"

static void	print_instra(t_instra value)
{
	if (value == PA)
		ft_printf("pa\n");
	else if (value == PB)
		ft_printf("pb\n");
	else if (value == RA)
		ft_printf("ra\n");
	else if (value == RB)
		ft_printf("rb\n");
	else if (value == RR)
		ft_printf("rr\n");
	else if (value == RRA)
		ft_printf("rra\n");
	else if (value == RRB)
		ft_printf("rrb\n");
	else if (value == RRR)
		ft_printf("rrr\n");
	else if (value == SA)
		ft_printf("sa\n");
	else if (value == SB)
		ft_printf("sb\n");
	else if (value == SS)
		ft_printf("ss\n");
}

static void	print_instructions(t_instras *list)
{
	while (list)
	{
		print_instra(list->value);
		list = list->next;
	}
}

static int	args_count(char *av[])
{
	int	i;

	i = 0;
	if (!av)
		return (i);
	while (av[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	t_push_swap	core;

	(void)argc;
  ft_memset(&core, 0, sizeof(core));
	core.av = extract_numbers(&argv[1]);
	core.ac = args_count(core.av);
	core.stack_b = NULL;
	if (checker(core.av))
		return (1);
	core.stack_a = parser(core.av);
	if (!core.stack_a)
		return (2);
	sorter(&core);
	optimizing(core.instras);
	print_instructions(core.instras);
	return (0);
}
