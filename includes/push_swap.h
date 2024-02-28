/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:42:00 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/28 14:39:37 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_stacks.h"

# include <stdio.h>
# include <stdlib.h>

void	radix_pass_even(t_stack **stack_a, t_stack	**stack_b, size_t	depth);

#endif