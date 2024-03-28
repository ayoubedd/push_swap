/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:23:27 by aeddaoud          #+#    #+#             */
/*   Updated: 2022/07/04 12:06:41 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

void		parser(t_instras **instras, t_node **head, char *args[]);
t_instras	*instractions_parser(void);
t_node		*arguments_parser(char *av[]);
char		**insert_line_in_array(char **array, char *line);
char		**merge_arrays(char **one, char **two);
size_t		array_len(char **array);
char		**args_cleanup(char *av[]);

#endif