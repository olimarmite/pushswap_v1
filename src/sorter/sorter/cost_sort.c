/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:42:28 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 21:23:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorter.h"

void	cost_based_sort(t_pushswap *pushswap)
{
	int		smallest_cost;
	int		smallest_cost_elem;
	int		current_cost;
	int		i;

	i = 0;
	while (i < pushswap->stack_b.item_count)
	{
		current_cost = double_goto_best_move_op_count(
				get_t_move(get_correct_index(pushswap->stack_b.content[i],
						&pushswap->stack_a), i), pushswap);
		if (i == 0 || current_cost < smallest_cost)
		{
			smallest_cost = current_cost;
			smallest_cost_elem = i;
		}
		i++;
	}
	double_goto_index(
		get_t_move(
			get_correct_index(pushswap->stack_b.content[smallest_cost_elem],
				&pushswap->stack_a), smallest_cost_elem), pushswap);
	pushswap_push(stack_id_a, pushswap);
}

void	best_goto_index(int index, t_stack_id stack_id, t_pushswap *pushswap)
{
	int		reverse;
	t_stack	*stack;

	reverse = 0;
	stack = pushswap_stack_from_id(stack_id, pushswap);
	if (index * 2 > stack->item_count)
	{
		reverse = 1;
	}
	goto_index(index, reverse, stack_id, pushswap);
}

int	calc_move_to_a_cost(
	t_move move,
	int reverse_a,
	int reverse_b,
	t_pushswap *pushswap)
{
	int	operation_count;

	operation_count = 0;
	if (reverse_b)
	{
		operation_count += (pushswap->stack_b.item_count - move.index_b);
		if (reverse_a)
		{
			operation_count = ft_max(operation_count,
					pushswap->stack_a.item_count - move.index_a);
		}
		else
			operation_count += move.index_a;
	}
	else
	{
		operation_count += move.index_b;
		if (reverse_a)
			operation_count += pushswap->stack_a.item_count - move.index_a;
		else
			operation_count = ft_max(operation_count, move.index_a);
	}
	return (operation_count);
}

int	double_goto_best_move_op_count(t_move move, t_pushswap *pushswap)
{
	int	reverse;
	int	best_instructions_count;
	int	current_instructions_count;

	reverse = 0;
	best_instructions_count = -1;
	while (reverse <= 3)
	{
		current_instructions_count = calc_move_to_a_cost(move,
				reverse & 1, reverse >> 1, pushswap);
		if ((best_instructions_count == -1)
			|| current_instructions_count <= best_instructions_count)
		{
			best_instructions_count = current_instructions_count;
		}
		reverse ++;
	}
	return (best_instructions_count);
}
