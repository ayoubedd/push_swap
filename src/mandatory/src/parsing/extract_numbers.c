/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:44:00 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/28 10:20:45 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	array_len(char **array)
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

static char	**merge_arrays(char **one, char **two)
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

static char	**insert_line_in_array(char **array, char *line)
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

char	**extract_numbers(char *av[])
{
	char	*tmp;
	char	**tmpp;
	char	**splits;
	char	**args;

	args = NULL;
	while (*av)
	{
		tmpp = args;
		if (ft_strchr(*av, ' '))
		{
			splits = ft_split(*av, ' ');
			args = merge_arrays(args, splits);
			free(splits);
		}
		else
		{
			tmp = ft_strdup(*av);
			args = insert_line_in_array(args, tmp);
		}
		free(tmpp);
		av++;
	}
	return (args);
}
