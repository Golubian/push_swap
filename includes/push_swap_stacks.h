/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:44:28 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/28 14:57:43 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STACKS_H
# define PUSH_SWAP_STACKS_H

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int content);
void	stack_addback(t_stack **head, t_stack *to_add);
void	stack_swap(t_stack **head, t_stack	*to_swap_a, t_stack	*to_swap_b);
void	stack_rot(t_stack **head);
void	stack_print(t_stack *head);
void	stack_put(t_stack **from, t_stack **to);

#endif