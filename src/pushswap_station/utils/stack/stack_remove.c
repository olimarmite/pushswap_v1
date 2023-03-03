/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:05:18 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 03:05:26 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Remove element at [index] in [stack]
 *
 * @return return 0 if success;
 */
int	stack_remove(int index, t_stack *stack)
{
	if (index < 0 || index >= stack->item_count)
		return (1);
	if (stack->item_count - index - 1 > 0)
	{
		ft_memmove(stack->content + index, stack->content + index + 1,
			stack->item_count - index - 1);
	}
	stack->content[stack->item_count - 1] = -1;
	stack->item_count --;
	return (0);
}
