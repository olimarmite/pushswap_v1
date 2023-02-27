/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:22:00 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 18:43:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

t_move	get_t_move(int index_a, int index_b)
{
	t_move	move;

	move.index_a = index_a;
	move.index_b = index_b;
	return (move);
}

int	double_goto_best_move(t_move move, t_pushswap *pushswap)
{
	int	reverse;
	int	best_reverse;
	int	best_instructions_count;
	int	current_instructions_count;

	reverse = 0;
	best_reverse = 0;
	best_instructions_count = -1;
	while (reverse <= 3)
	{
		current_instructions_count = calc_move_to_a_cost(move,
				reverse & 1, reverse >> 1, pushswap);
		if ((best_instructions_count == -1)
			|| current_instructions_count <= best_instructions_count)
		{
			best_instructions_count = current_instructions_count;
			best_reverse = reverse;
		}
		reverse ++;
	}
	return (best_reverse);
}

int	get_correct_index(int element, t_stack *stack)
{
	int	i;
	int	last_bigger_index;
	int	last_bigger;

	last_bigger_index = -1;
	last_bigger = -1;
	i = 0;
	if (stack->item_count <= 0)
		return (0);
	while (i < stack->item_count)
	{
		if (stack->content[i] >= element)
		{
			if (stack->content[i] < last_bigger || last_bigger == -1)
			{
				last_bigger = stack->content[i];
				last_bigger_index = i;
			}
		}
		i++;
	}
	if (last_bigger_index == -1)
		return (stack_min_index(stack));
	return (last_bigger_index);
}
