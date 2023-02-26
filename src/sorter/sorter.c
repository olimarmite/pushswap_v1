/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:07:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 22:48:16 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_main(t_pushswap *pushswap, int chunk_count_modifier)
{
	int	len;
	int	i;

	if (pushswap->stack_a.item_count <= 5)
	{
		sort_small(pushswap);
	}
	else
	{
		i = 0;
		presort(1 + chunk_count_modifier, pushswap);
		len = pushswap->stack_b.item_count;
		while (i < len)
		{
			cost_based_sort(pushswap);
			i++;
		}
		best_goto_index(stack_min_index(&pushswap->stack_a),
			stack_id_a, pushswap);
		pushswap_operations_reduce(pushswap);
	}
	return (0);
}

int	proximity_sort(t_pushswap *pushswap)
{
	int	max_index;

	while (pushswap->stack_b.item_count > 0)
	{
		max_index = stack_max_index(&pushswap->stack_b);
		if (max_index != -1)
		{
			double_goto_index(get_t_move(
					get_correct_index(pushswap->stack_b.content[max_index],
						&pushswap->stack_a),
					stack_max_index(&pushswap->stack_b)), pushswap);
		}
		pushswap_push(stack_id_a, pushswap);
	}
	return (0);
}

int	double_goto_index(t_move move, t_pushswap *pushswap)
{
	int	reverse;

	if (move.index_a == -1 || move.index_b == -1)
		return (-1);
	reverse = double_goto_best_move(move, pushswap);
	goto_index(move.index_a, reverse & 1, stack_id_a, pushswap);
	goto_index(move.index_b, reverse >> 1, stack_id_b, pushswap);
	return (0);
}

void	goto_index(int index, int reverse,
	t_stack_id stack_id, t_pushswap *pushswap)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = pushswap_stack_from_id(stack_id, pushswap);
	if (reverse != 0)
	{
		while (i < stack->item_count - index)
		{
			pushswap_rotate(reverse, stack_id, pushswap);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			pushswap_rotate(reverse, stack_id, pushswap);
			i++;
		}
	}
}
