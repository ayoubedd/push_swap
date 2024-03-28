/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:12:23 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 12:17:23 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_bool	check_syntax(char *nums[])
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		if (nums[i][0] == '-' || nums[i][0] == '+')
			j = 1;
		else
			j = 0;
		while (nums[i][j])
		{
			if (!(nums[i][j] >= '0' && nums[i][j] <= '9'))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
