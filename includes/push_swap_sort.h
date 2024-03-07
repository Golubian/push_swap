/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:22 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/07 10:05:40 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORT_H
# define PUSH_SWAP_SORT_H

# include "push_swap_stacks.h"

int		get_at_pos(t_stack *stack, int pos);
int		get_median(t_stack *stack);
int		get_pos_from_perc(t_stack *stack, float perc);
int		stack_contains_fork(t_stack *stack, int min, int max);
int		get_closest_fork_pos(t_stack *stack, int min, int max);

int		is_sorted(t_stack *stack, int ascending);

void	put_fork(t_stack *stack_a, t_stack *stack_b, float range, int median);
void	finalize_sort(t_stack *stack_a, t_stack *stack_b);

#endif