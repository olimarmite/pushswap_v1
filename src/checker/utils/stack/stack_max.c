/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:12 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 18:35:41 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Return the biggest element of [stack]
 *
 * Return -1 if stack is empty.
 */
int	stack_max(t_stack *stack)
{
	int	i;
	int	max;

	if (stack->item_count <= 0)
		return (-1);
	i = 0;
	max = stack->content[i];
	while (i < stack->item_count)
	{
		if (stack->content[i] > max)
		{
			max = stack->content[i];
		}
		i++;
	}
	return (max);
}
