/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:22 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 16:24:30 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SORT_H
# define PUSH_SWAP_SORT_H

# include "push_swap_stacks.h"

int	get_at_pos(t_stack *stack, int pos);
int	get_median(t_stack *stack);
int	get_pos_from_perc(t_stack *stack, float perc);

#endif