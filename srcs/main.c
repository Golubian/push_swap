/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:41:13 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 11:56:58 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_print(t_stack *stack)
{
	t_list	*current;

	printf("Stack: ");
	if (!stack)
		return (printf("<NULL>\n"));
	current = stack->head;
	printf("%i ", current->content);
	while (current->next)
	{
		current = current->next;
		printf(" -> %i", current->content);
	}
	printf(" -> <NULL>\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (argc <= 1)
		return (printf("Usage example:\n./push_swap \"9 2 -7 1 23 42\"\n"), 1);
	else if (argc == 2)
	{
		if (!single_input_is_valid(argv[1]))
			return (printf("ERROR"), 1);
		a = get_stack_from_input(argv[1]);
	}
	else
	{
		if (!multi_input_is_valid(argc, argv))
			return (printf("ERROR"), 1);
		a = get_stack_from_inputs(argc, argv);
	}
	if (!is_sorted(a) && stack_size(a) > 15)
		radix_sort(a, b);
	else if (!is_sorted(a))
		tiny_sort(a, b);
	stack_free(a);
	stack_free(b);
}
