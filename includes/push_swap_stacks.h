/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:44:28 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 13:52:09 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STACKS_H
# define PUSH_SWAP_STACKS_H

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	struct s_list	*head;
}	t_stack;

t_list	*stack_new(int content);
void	stack_addback(t_stack *stack, t_list *to_add);
void	stack_rot(t_stack *stack);
void	stack_rrot(t_stack *stack);
void	stack_put(t_stack *from, t_stack *to);
void	stack_swap(t_stack *stack);

#endif