/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:54:00 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 13:41:44 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_new(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	stack_addback(t_stack *stack, t_list *to_add)
{
	t_list	*current;

	if (!stack->head)
	{
		stack->head = to_add;
		return ;
	}
	current = stack->head;
	while (current && current->next)
		current = current->next;
	current->next = to_add;
}

void	stack_addfront(t_stack *stack, t_list *to_add)
{
	to_add->next = stack->head;
	stack->head = to_add;
}

void	stack_put(t_stack *from, t_stack *to)
{
	t_list	*to_add;

	if (!from->head)
		return ;
	to_add = from->head;
	from->head = from->head->next;
	stack_addfront(to, to_add);
}
