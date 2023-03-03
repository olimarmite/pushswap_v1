/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:54:39 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 22:18:20 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Copy a stack [stack_in]
 *
 * Return new copied t_stack
 * Return t_stack with capacity of 0 in case of error
 */
t_stack	stack_copy(t_stack *stack_in)
{
	t_stack	stack_out;

	stack_out = stack_create(stack_in->capacity, stack_in->id);
	if (stack_out.capacity > 0)
	{
		ft_memmove(stack_out.content, stack_in->content, stack_in->item_count);
		stack_out.item_count = stack_in->item_count;
	}
	return (stack_out);
}
