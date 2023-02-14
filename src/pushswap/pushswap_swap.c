/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:17:42 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:17:48 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
