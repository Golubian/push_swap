/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:29:31 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 13:33:55 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_MOVES_H
# define PUSH_SWAP_MOVES_H

# include "push_swap_stacks.h"

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif