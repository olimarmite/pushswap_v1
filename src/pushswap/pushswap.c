/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:21:25 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 09:21:17 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_pushswap	pushswap_create(int elements_count)
{
	t_pushswap	pushswap;
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a = stack_create(elements_count + 1, stack_id_a);
	stack_b = stack_create(elements_count + 1, stack_id_b);
	pushswap.elements_count = elements_count;
	pushswap.stack_a = stack_a;
	pushswap.stack_b = stack_b;
	pushswap.operations_list = stack_create(5500, 3);
	return (pushswap);
}

/**
 * Rotate the [stack_id] in order of [reverse]
 *
 * if [reverse] is !0,
 * the first element of the stack is moved to the last position
 *
 * else,
 * the last element of the stack is moved to the first position
 *
 * Return 0 if element had been moved;
 * Return 1 if no elements had been moved;
 * Return -1 in case of malloc error;
 */
int	pushswap_rotate(int reverse, t_stack_id stack_id, t_pushswap *pushswap)
{
	t_operation	operation;

	if (stack_id == stack_id_a)
	{
		operation = ra;
		if (stack_rotate(reverse, &pushswap->stack_a) != 0)
			return (1);
	}
	else
	{
		operation = rb;
		if (stack_rotate(reverse, &pushswap->stack_b) != 0)
			return (1);
	}
	if (reverse)
		operation += 3;
	return (pushswap_add_operation(operation, pushswap));
}

/**
 * Swap the two firsts elements of [stack_id]
 *
 * Return 0 if elements have been moved;
 * Return 1 if no elements had been moved;
 * Return -1 in case of malloc error;
 */
int	pushswap_swap(t_stack_id stack_id, t_pushswap *pushswap)
{
	t_operation	operation;

	if (stack_id == stack_id_a)
	{
		operation = sa;
		if (stack_swap(&pushswap->stack_a) != 0)
			return (1);
	}
	else
	{
		operation = sb;
		if (stack_swap(&pushswap->stack_b) != 0)
			return (1);
	}
	return (pushswap_add_operation(operation, pushswap));
}

/**
 * Push the first element of opposite stack on the top of [to_stack]
 *
 * Return 0 if element have been moved;
 * Return -1 in case of malloc error;
 */
int	pushswap_push(t_stack_id to_stack_id, t_pushswap *pushswap)
{
	t_operation	operation;

	if (to_stack_id == stack_id_a)
	{
		operation = pa;
		if (stack_push(&pushswap->stack_b, &pushswap->stack_a) != 0)
			return (1);
	}
	else
	{
		operation = pb;
		if (stack_push(&pushswap->stack_a, &pushswap->stack_b) != 0)
			return (1);
	}
	return (pushswap_add_operation(operation, pushswap));
}


/**
 * Add [operation] to operations
 *
 * Return 0 if success
 * Return -1 if error
 */
int	pushswap_add_operation(t_operation operation, t_pushswap *pushswap)
{
	if (stack_add(operation ,&pushswap->operations_list) == 0)
		return (0);
	else
		return (-1);
}

