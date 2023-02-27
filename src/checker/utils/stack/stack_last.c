/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:16:49 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 23:20:11 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Return last element of [stack]
 *
 * @return return -1 if the stack is empty;
 */
int	stack_last(t_stack *stack)
{
	if (stack->item_count <= 0)
	{
		return (-1);
	}
	return (stack->content[stack->item_count - 1]);
}
