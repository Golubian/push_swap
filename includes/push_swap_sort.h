/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:22 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 11:02:51 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORT_H
# define PUSH_SWAP_SORT_H

# include "push_swap_stacks.h"

void	radix_sort(t_stack	*stack_a, t_stack *stack_b);
void	tiny_sort( t_stack	*stack_a, t_stack *stack_b);

int		is_sorted(t_stack *stack);
int		is_sorted_rev(t_stack *stack);

int		get_digit_at_pos(int base10, int pos);
int		get_closest_pos(t_stack *stack, t_list *target);
int		stack_contains_bit_unset(t_stack *stack, int pos);

#endif
