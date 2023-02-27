/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:06:01 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/17 08:37:19 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Add element at the end of [stack]
 *
 * @return return 0 if success;
 */
int	stack_add(int element, t_stack *stack)
{
	if (stack->item_count >= stack->capacity)
	{
		if (stack_grow(stack) != 0)
			return (-1);
	}
	stack->content[stack->item_count] = element;
	stack->item_count ++;
	return (0);
}
