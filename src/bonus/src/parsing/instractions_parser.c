/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:42:13 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/06 16:50:05 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "get_next_line.h"

static void	add_back(t_instras **head, t_instras *node)
{
	t_instras	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

static t_instras	*make_node(t_instra type)
{
	t_instras	*instraction;

	instraction = malloc(sizeof(t_instras));
	if (!instraction)
		return (NULL);
	instraction->value = type;
	instraction->next = NULL;
	return (instraction);
}

static t_instras	*interpreter(char *line)
{
	if (!ft_strncmp(line, "pa\n", ft_strlen(line) + 1))
		return (make_node(PA));
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line) + 1))
		return (make_node(PB));
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line) + 1))
		return (make_node(SA));
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line) + 1))
		return (make_node(SB));
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line) + 1))
		return (make_node(SS));
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line) + 1))
		return (make_node(RA));
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line) + 1))
		return (make_node(RB));
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line) + 1))
		return (make_node(RRA));
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line) + 1))
		return (make_node(RRB));
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line) + 1))
		return (make_node(RR));
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line) + 1))
		return (make_node(RRR));
	return (NULL);
}

t_instras	*instractions_parser(void)
{
	char		*line;
	t_instras	*head;
	t_instras	*tmp;

	head = NULL;
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		tmp = interpreter(line);
		if (!tmp)
		{
			ft_printr("Error\n");
			exit(2);
		}
		free(line);
		add_back(&head, tmp);
	}
	return (head);
}
