/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:15:20 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/06 16:51:29 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checking.h"
#include "libft.h"

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
	if (check_syntax(av)
		|| check_duplicate(av)
		|| check_overflow(av)
		|| check_empty_argument(av))
	{
		ft_printr("Error\n");
		return (TRUE);
	}
	return (FALSE);
}
