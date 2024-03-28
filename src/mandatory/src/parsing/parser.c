/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:30:59 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/03 11:10:11 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "parsing.h"

static t_node	*build_node(char *str)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->value = ft_atoi(str);
	return (tmp);
}

void	add_back(t_node	**head, t_node *node)
{
	t_node	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

t_node	*parser(char *av[])
{
	size_t	i;
	t_node	*tmp;
	t_node	*head;

	i = 0;
	head = NULL;
	while (av[i])
	{
		tmp = build_node(av[i]);
		add_back(&head, tmp);
		i++;
	}
	return (head);
}
