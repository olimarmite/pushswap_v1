/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_stack_from_id.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:44:01 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 05:20:09 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * Return pointer on stack of [pushswap] by [stack_id]
 */
t_stack	*pushswap_stack_from_id(t_stack_id stack_id, t_pushswap *pushswap)
{
	if (stack_id == stack_id_a)
	{
		return (&pushswap->stack_a);
	}
	else
	{
		return (&pushswap->stack_b);
	}
}
