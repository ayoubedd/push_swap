/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:30:32 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/02 08:11:42 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "push_swap.h"

void		first_phase(t_push_swap *core);
void		second_phase(t_push_swap *core);
void		sorter(t_push_swap *core);
t_chunk		*build_chunks(t_node *numbers, t_mode *mode);
t_node		*sort_numbers(t_node *stack);
int			nums_count(t_node *nums);
t_node		*copy_stack(t_node *stack);
void		small_numbers(t_push_swap *core, enum e_mode mode);
t_node		*get_node_by_idx(t_node *list, size_t idx);
t_chunk		*last_chunk(t_chunk *chunks);
t_way		which_way(t_node *stack, t_node *node);
t_bool		check_num_in_stack(t_node *stack, int num);
void		case_one(t_node **stack_a, t_instras **list);
void		case_two(t_node **stack_a, t_instras **list);
void		case_three(t_node **stack_a, t_instras **list);
void		case_four(t_node **stack_a, t_instras **list);
void		case_five(t_node **stack_a, t_instras **list);
void		push_first_n_nums(t_push_swap *core, size_t n);

#endif
