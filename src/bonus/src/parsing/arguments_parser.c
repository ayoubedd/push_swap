/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:13:26 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/04 12:26:05 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	add_back(t_node **head, t_node *node)
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

static t_node	*build_node(int value)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_node	*arguments_parser(char *av[])
{
	size_t		i;
	t_node		*head;
	t_node		*tmp;

	i = 0;
	head = NULL;
	while (av[i])
	{
		tmp = build_node(ft_atoi(av[i]));
		if (!tmp)
			break ;
		add_back(&head, tmp);
		i++;
	}
	return (head);
}
