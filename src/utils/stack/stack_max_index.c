/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:12 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/25 21:17:39 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Return the index of biggest element of [stack]
 *
 * Return -1 if stack is empty.
 */
int	stack_max_index(t_stack *stack)
{
	int	i;
	int	index;
	int	max;


	if (stack->item_count <= 0)
		return (-1);
	i = 0;
	index = 0;
	max = stack->content[i];
	while (i < stack->item_count)
	{
		if (stack->content[i] > max)
		{
			index = i;
			max = stack->content[i];
		}
		i++;
	}
	return (index);
}
