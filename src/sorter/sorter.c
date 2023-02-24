/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:07:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 05:31:42 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_main(t_pushswap *pushswap)
{

	presort(5, pushswap);
	//printf("\n[%d]\n", calc_move_cost(get_t_move(0, 1), 1, 0, pushswap));
	proximity_sort(pushswap);
	return (0);
}

int	proximity_sort(t_pushswap *pushswap)
{
	// double_goto_index(get_t_move(0,
	// 		100), pushswap);
	//stack_print(&pushswap->stack_b);
	// printf("#%d#\n", double_goto_best_move(get_t_move(0,
	// 			50), pushswap));
	while (pushswap->stack_b.item_count > 0)
	{
		double_goto_index(get_t_move(0,
				stack_max_index(&pushswap->stack_b)), pushswap);
		// double_goto_index(get_t_move(0,499), pushswap);
		pushswap_push(stack_id_a, pushswap);
	}

	return (0);
}

int	double_goto_index(t_move move, t_pushswap *pushswap)
{
	int	reverse;

	//printf("--%d, %d\n", move.index_a, move.index_b);
	reverse = double_goto_best_move(move, pushswap);
	//printf("\nreverse a : %d, reverse b: %d\n", reverse & 1, reverse >> 1);
	goto_index(move.index_a, reverse & 1, stack_id_a, pushswap);
	goto_index(move.index_b, reverse >> 1, stack_id_b, pushswap);
	return (0);
}

void	goto_index(int index, int reverse
	, t_stack_id stack_id, t_pushswap *pushswap)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = pushswap_stack_from_id(stack_id, pushswap);
	//printf("GOTO : %d\n", stack->item_count - index);
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
	//	printf("\n**[%d, %d]**\n", reverse & 1, reverse >> 1);
		current_instructions_count = calc_move_to_a_cost(move, reverse & 1,reverse >> 1, pushswap);
		if ((best_instructions_count == -1) || current_instructions_count <= best_instructions_count)
		{
			best_instructions_count = current_instructions_count;
			best_reverse = reverse;
		}
		reverse ++;
	}
	return (best_reverse);
}


int	calc_move_to_a_cost(
	t_move move,
	int reverse_a,
	int reverse_b,
	t_pushswap *pushswap)

{
	int	operation_count;
	//printf("REVERSE ? A : %d \n", reverse_a);
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
		{
			operation_count += move.index_a;
		}
	}
	else
	{
		operation_count += move.index_b;
		if (reverse_a)
		{
			operation_count += pushswap->stack_a.item_count - move.index_a;
		}
		else
		{
			operation_count = ft_max(operation_count, move.index_a);
		}
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
