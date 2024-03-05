/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inputs.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:12:57 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 16:15:20 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INPUTS_H
# define PUSH_SWAP_INPUTS_H

# include "push_swap_stacks.h"

int		single_input_is_valid(char *input);
int		multi_input_is_valid(int elems, char **input);

t_stack	*get_stack_from_input(char *input);
t_stack	*get_stack_from_inputs(int elems, char **input);

int		check_valid_ints(char **split_input);

#endif