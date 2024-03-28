/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:47:51 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/04 12:36:10 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	array_len(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

static void	move_ptrs(char **lines, char **one, char **two)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (one)
	{
		while (one[i])
		{
			lines[i] = one[i];
			i++;
		}
	}
	if (two)
	{
		while (two[j])
		{
			lines[i + j] = two[j];
			j++;
		}
	}
	lines[i + j] = NULL;
}

char	**merge_arrays(char **one, char **two)
{
	size_t	size;
	char	**lines;

	if (!one && !two)
		return (NULL);
	size = array_len(one) + array_len(two) + 1;
	lines = (char **)malloc(sizeof(char **) * size);
	if (!lines)
		return (NULL);
	move_ptrs(lines, one, two);
	return (lines);
}

char	**insert_line_in_array(char **array, char *line)
{
	size_t	i;
	size_t	size;
	char	**lines;

	i = 0;
	size = array_len(array) + 2;
	lines = (char **)malloc(sizeof(char **) * size);
	if (!lines)
		return (NULL);
	if (array)
	{
		while (array[i])
		{
			lines[i] = array[i];
			i++;
		}
	}
	lines[i] = line;
	lines[i + 1] = NULL;
	return (lines);
}
