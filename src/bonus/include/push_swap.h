/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:15:44 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/06 16:44:35 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"
# include "ft_printr.h"
# include "libft.h"

typedef enum e_bool {
	FALSE,
	TRUE
}	t_bool;

typedef enum e_instra {
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR
}	t_instra;

typedef struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_instras {
	t_instra			value;
	struct s_instras	*next;
}	t_instras;

#endif