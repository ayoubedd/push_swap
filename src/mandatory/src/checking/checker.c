/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:02:24 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:10:59 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checking.h"
#include "parsing.h"

static t_bool	check_count(char **nums)
{
	size_t	i;

	i = 0;
	while (nums[i])
		i++;
	if (i <= 1)
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	check_empty_argument(char **nums)
{
	size_t	i;

	i = 0;
	while (nums[i])
	{
		if (nums[i][0] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	checker(char *av[])
{
	if (!av)
		return (TRUE);
	if (check_syntax(av)
		|| check_duplicate(av)
		|| check_overflow(av)
		|| check_empty_argument(av))
	{
		ft_printr("Error\n");
		return (TRUE);
	}
	if (check_count(av) || check_sorted(av))
		return (TRUE);
	return (FALSE);
}
