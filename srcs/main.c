/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:41:13 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/28 15:46:43 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("\nStack A:\n");
	stack_print(a);
	printf("\nStack B:\n");
	stack_print(b);
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	time_t	t;
	int		i;

	a = 0;
	b = 0;
	i = 0;
	srand((unsigned) time(&t));
	while (i++ < 6)
		stack_addback(&a, stack_new(6 - i));
	// while (i++ < 10000)
	// 	stack_rot(&a);
	print_stacks(a, b);
	radix_pass_even(&a, &b, 0);
	print_stacks(a, b);
}
