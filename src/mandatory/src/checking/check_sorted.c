/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:43:18 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/01 10:41:10 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_sorted(char *nums[])
{
	int		tmp;
	size_t	i;

	i = 0;
	tmp = ft_atoi(nums[0]);
	while (nums[i])
	{
		if (tmp > ft_atoi(nums[i]))
			return (FALSE);
		tmp = ft_atoi(nums[i]);
		i++;
	}
	return (TRUE);
}
