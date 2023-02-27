/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:04:44 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/17 10:28:39 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Insert [element] at [index] in [stack]
 *
 * @return return 0 if success;
 */
int	stack_insert(int element, int index, t_stack *stack)
{
	if (index > stack->item_count || stack->item_count >= stack->capacity)
		return (1);
	if (stack->item_count > index)
	{
		ft_memmove(stack->content + index + 1, stack->content + index,
			stack->item_count - index);
		if (stack->item_count + 1 < stack->capacity)
			stack->content[stack->item_count + 1] = -1;
	}
	stack->content[index] = element;
	stack->item_count ++;
	return (0);
}
