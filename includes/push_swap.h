/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:42:00 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 13:34:34 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//stacks.c
# include "push_swap_stacks.h"
# include "push_swap_moves.h"

# include <stdio.h>
# include <stdlib.h>

//ft_split.c
char	**ft_split(char const *s, char c);

//ft_atoi.c
int		ft_atoi(const char *nptr);
int		check_valid_ints(char **split_input);

//input_validity.c
int		single_input_is_valid(char *input);
int		multi_input_is_valid(int elems, char **input);

//input_utils.c
t_stack	*get_stack_from_input(char *input);
t_stack	*get_stack_from_inputs(int elems, char **input);

#endif