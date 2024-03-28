/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:19:49 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/19 13:11:58 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_printr.h"

typedef enum e_bool {
	FALSE,
	TRUE
}	t_bool;

enum e_mode {
	MODE_2,
	MODE_3,
	MODE_5,
	MODE_100,
	MODE_500,
};

typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_chunk {
	int				start;
	int				end;
	struct s_chunk	*next;
}	t_chunk;

typedef struct s_mode {
	enum e_mode	mode;
	int			chunk_size;
}	t_mode;

typedef enum s_instra {
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
	RRR,
	SKIP
}	t_instra;

typedef struct s_instractions {
	t_instra				value;
	struct s_instractions	*next;
	struct s_instractions	*prev;
}	t_instras;

typedef struct s_push_swap {
	t_node			*stack_a;
	t_node			*stack_b;
	t_node			*sorted;
	t_instras		*instras;
	t_chunk			*chunks;
	int				ac;
	char			**av;
}	t_push_swap;

typedef enum e_way {
	TOP,
	BOTTOM
}	t_way;

#endif