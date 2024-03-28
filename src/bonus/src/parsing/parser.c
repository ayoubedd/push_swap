/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:30:59 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:13:21 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "libft.h"

char	**args_cleanup(char *av[])
{
	int		i;
	char	**tmpp;
	char	**splits;
	char	**args;

	i = 0;
	args = NULL;
	while (av[i])
	{
		tmpp = args;
		if (ft_strchr(av[i], ' '))
		{
			splits = ft_split(av[i], ' ');
			args = merge_arrays(args, splits);
			free(splits);
		}
		else
			args = insert_line_in_array(args, ft_strdup(av[i]));
		free(tmpp);
		i++;
	}
	return (args);
}

void	parser(t_instras **instras, t_node **head, char *args[])
{
	*instras = instractions_parser();
	*head = arguments_parser(args);
}
