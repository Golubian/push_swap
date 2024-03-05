/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:35:47 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 13:39:04 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	printf("rr\n");
	stack_rot(stack_a);
	stack_rot(stack_b);
}
