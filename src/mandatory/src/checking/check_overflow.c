/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:23:59 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/06 15:56:31 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_bool	check_overflow(char *nums[])
{
	int		tmp;
	size_t	i;

	i = 0;
	while (nums[i])
	{
		tmp = ft_atoi(nums[i]);
		if (tmp > 0 && nums[i][0] == '-')
			return (TRUE);
		else if ((tmp < 0 && nums[i][0] == '+')
				|| (tmp < 0 && (nums[i][0] >= '0' && nums[i][0] <= '9')))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
