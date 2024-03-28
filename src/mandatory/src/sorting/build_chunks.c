/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:52:12 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/02 11:26:25 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sorting.h"

struct s_range {
	int	start;
	int	end;
};

typedef struct s_range	t_range;

static t_chunk	*build_chunk(int start, int end)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (NULL);
	chunk->start = start;
	chunk->end = end;
	chunk->next = NULL;
	return (chunk);
}

static void	add_back(t_chunk **head, t_chunk *chunk)
{
	t_chunk	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = chunk;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = chunk;
}

static size_t	nodes_count(t_node *list)
{
	size_t	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	get_range(t_range *range, t_node *sorted, size_t offset)
{
	size_t			i;
	t_node			*tmp;
	static size_t	idx;

	i = 0;
	if (idx == 0)
		idx = 1;
	offset *= idx;
	tmp = get_node_by_idx(sorted, nodes_count(sorted) / 2 - 1);
	while (tmp->prev && i < offset)
	{
		tmp = tmp->prev;
		i++;
	}
	range->start = tmp->value;
	i = 0;
	tmp = get_node_by_idx(sorted, nodes_count(sorted) / 2 - 1);
	while (tmp->next && i < offset)
	{
		tmp = tmp->next;
		i++;
	}
	range->end = tmp->value;
	idx++;
}

t_chunk	*build_chunks(t_node *nums, t_mode *mode)
{
	t_chunk	*chunks;
	t_range	range;
	t_chunk	*tmp;

	chunks = NULL;
	range.start = -1;
	range.end = -1;
	while (TRUE)
	{
		get_range(&range, nums, mode->chunk_size);
		if (chunks)
			if (last_chunk(chunks)->end == range.end
				&& last_chunk(chunks)->start == range.start)
				break ;
		tmp = build_chunk(range.start, range.end);
		add_back(&chunks, tmp);
	}
	return (chunks);
}
