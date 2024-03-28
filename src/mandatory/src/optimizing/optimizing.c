/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:39:14 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:12:33 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(t_instras *list)
{
	list->value = RR;
	list->next->value = SKIP;
}

static void	rrr(t_instras *list)
{
	list->value = RRR;
	list->next->value = SKIP;
}

void	optimizing(t_instras *list)
{
	while (list)
	{
		if (!list->next || list->value == SKIP)
		{
			list = list->next;
			continue ;
		}
		if (list->value == RRA && list->next->value == RRB)
			rrr(list);
		if (list->value == RRB && list->next->value == RRA)
			rrr(list);
		if (list->value == RA && list->next->value == RB)
			rr(list);
		if (list->value == RB && list->next->value == RA)
			rr(list);
		list = list->next;
	}
}
