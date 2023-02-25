/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:12 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/25 21:17:18 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Return the index of smallest element of [stack]
 *
 * Return -1 if stack is empty.
 */
int	stack_min_index(t_stack *stack)
{
	int	i;
	int	index;
	int	min;


	if (stack->item_count <= 0)
		return (-1);
	i = 0;
	index = 0;
	min = stack->content[i];
	while (i < stack->item_count)
	{
		if (stack->content[i] < min)
		{
			index = i;
			min = stack->content[i];
		}
		i++;
	}
	return (index);
}
