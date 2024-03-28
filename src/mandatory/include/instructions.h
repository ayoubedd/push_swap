/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:26:27 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/06/30 11:37:28 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "push_swap.h"

void	ra(t_node **stack_a, t_instras **list);
void	sa(t_node **stack_a, t_instras **list);
void	sb(t_node **stack_b, t_instras **list);
void	sb(t_node **stack_b, t_instras **list);
void	pa(t_node **stack_a, t_node **stack_b, t_instras **list);
void	pb(t_node **stack_a, t_node **stack_b, t_instras **list);
void	ra(t_node **stack_a, t_instras **list);
void	rb(t_node **stack_b, t_instras **list);
void	rra(t_node **stack_a, t_instras **list);
void	rrb(t_node **stack_b, t_instras **list);
void	rr(t_node **stack_a, t_node **stack_b, t_instras **list);
void	rrr(t_node **stack_a, t_node **stack_b, t_instras **list);
t_node	*last_node(t_node *stack);
void	log_instraction(t_instras **list, t_instra instra);

#endif