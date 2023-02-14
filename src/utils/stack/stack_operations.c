/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:22 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 02:32:06 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Rotate the [stack] in order of [reverse]
 *
 * if [reverse] is !0,
 * the first element of the stack is moved to the last position
 *
 * else,
 * the last element of the stack is moved to the first position
 *
 * Return 0 if element had been moved;
 */
int	stack_rotate(int reverse, t_stack *stack)
{
	if (stack->item_count <= 1)
		return (1);
	if (reverse != 0)
	{
		stack_insert(stack_first(stack), stack->item_count, stack);
		stack_remove(0, stack);
	}
	else
	{
		stack_insert(stack_last(stack), 0, stack);
		stack_remove(stack->item_count - 1, stack);
	}
	return (0);
}

/**
 * Swap the two firsts elements of [stack]
 *
 * Return 0 if elements have been moved;
 */
int	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->item_count <= 1)
		return (1);
	tmp = stack->content[1];
	stack->content[1] = stack->content[0];
	stack->content[0] = tmp;
	return (0);
}

/**
 * Push the first element of [stack] on the top of [toStack]
 *
 * Return 0 if element have been moved;
 */
int	stack_push(t_stack *stack, t_stack *to_stack)
{
	if (stack->item_count <= 0)
		return (1);
	stack_insert(stack->content[0], 0, to_stack);
	stack_remove(0, stack);
	return (0);
}
