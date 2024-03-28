/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:03:05 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/27 11:49:34 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	array_len(char *nums[])
{
	size_t	i;

	i = 0;
	while (nums[i])
		i++;
	return (i);
}

static int	*to_ints(char *nums[])
{
	int		*tmp;
	size_t	i;
	size_t	size;

	i = 0;
	size = array_len(nums);
	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (NULL);
	while (nums[i])
	{
		tmp[i] = ft_atoi(nums[i]);
		i++;
	}
	return (tmp);
}

t_bool	check_duplicate(char *nums[])
{
	int		*ints;
	size_t	i;
	size_t	j;

	i = 0;
	ints = to_ints(nums);
	if (!ints)
		return (TRUE);
	while (nums[i])
	{
		j = 0;
		while (nums[j])
		{
			if (ints[i] == ints[j] && i != j)
			{
				free(ints);
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	free(ints);
	return (FALSE);
}
