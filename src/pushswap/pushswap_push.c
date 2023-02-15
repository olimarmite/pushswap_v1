/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:18:27 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 21:29:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	return (pushswap_operations_add(operation, pushswap));
}
