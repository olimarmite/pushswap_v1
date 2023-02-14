/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:06 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:17:07 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
