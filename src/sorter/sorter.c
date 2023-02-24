/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:07:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 15:19:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_main(t_pushswap *pushswap)
{
	int len;
	int i = 0;
	presort(20, pushswap);
	// proximity_sort(pushswap);
	len = pushswap->stack_b.item_count;
	while (i < len)
	{
		cost_based_sort(pushswap);
		pushswap_push(stack_id_a, pushswap);
		i++;
	}
	// pushswap_operations_reduce(pushswap);
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

int	cost_based_sort(t_pushswap *pushswap)
{
	int		smallest_cost;
	int		smallest_cost_elem;
	int		current_cost;
	int		i;

	current_cost = -1;
	smallest_cost = -1;
	smallest_cost_elem = -1;
	i = 0;
	while (i < pushswap->stack_b.item_count)
	{
		current_cost = double_goto_best_move_op_count(
				get_t_move(get_correct_index(pushswap->stack_b.content[i],
						&pushswap->stack_a), i), pushswap);
		if (smallest_cost_elem == -1 || current_cost < smallest_cost)
		{
			smallest_cost = current_cost;
			smallest_cost_elem = i;
		}
		i++;
	}
	if (smallest_cost != -1)
		double_goto_index(
			get_t_move(
				get_correct_index(pushswap->stack_b.content[smallest_cost_elem],
					&pushswap->stack_a), smallest_cost_elem), pushswap);
	return (0);
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
		if (stack->content[i] > element)
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

int	double_goto_index(t_move move, t_pushswap *pushswap)
{
	int	reverse;

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

t_move	get_t_move(int index_a, int index_b)
{
	t_move	move;

	move.index_a = index_a;
	move.index_b = index_b;
	return (move);
}
