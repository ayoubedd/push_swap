/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:34:48 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 14:25:01 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "checking.h"
#include "sorting.h"

static int	args_count(char *av[])
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	t_instras	*head;
	t_node		*stack_a;
	t_node		*stack_b;
	char		**av;

	(void)argc;
	head = NULL;
	stack_a = NULL;
	stack_b = NULL;
	av = args_cleanup(&argv[1]);
	if (!av)
		return (0);
	if (checker(av))
		return (1);
	parser(&head, &stack_a, av);
	if (!stack_a)
		return (2);
	sorter(&stack_a, &stack_b, head);
	if (sorted_check(&stack_a, args_count(av)))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}
