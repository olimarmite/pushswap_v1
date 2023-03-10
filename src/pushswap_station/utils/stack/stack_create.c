/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:55:05 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 18:17:42 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
/**
 * @brief Create empty stack with a maximum [capacity]
 *
 * Return t_stack
 * Return t_stack with capacity of 0 in case of error
 */
t_stack	stack_create(int capacity, int id)
{
	int		*content;
	t_stack	stack;

	if (capacity > 0)
	{
		content = malloc(capacity * sizeof(int));
		if (content)
			content[0] = -1;
		else
			capacity = 0;
	}
	else
	{
		capacity = 0;
		content = NULL;
	}
	stack.capacity = capacity;
	stack.content = content;
	stack.item_count = 0;
	stack.id = id;
	return (stack);
}
