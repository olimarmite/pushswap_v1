/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_indexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:03:45 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 03:04:01 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * Return the first index of [element] in [stack]
 *
 * Return -1 if [element] is not found.
 */
int	stack_indexof(int element, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->content[i] != element)
	{
		if (i >= stack->item_count)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}
