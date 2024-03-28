/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_instraction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:43:13 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:37:28 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_back(t_instras **instras, t_instras *instra)
{
	t_instras	*tmp;

	tmp = *instras;
	if (!tmp)
	{
		*instras = instra;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = instra;
	instra->prev = tmp;
}

static t_instras	*build_node(t_instra instra)
{
	t_instras	*tmp;

	tmp = malloc(sizeof(t_instras));
	if (!tmp)
		return (NULL);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->value = instra;
	return (tmp);
}

void	log_instraction(t_instras **list, t_instra instra)
{
	t_instras	*node;

	node = build_node(instra);
	if (!node)
		return ;
	add_back(list, node);
}
