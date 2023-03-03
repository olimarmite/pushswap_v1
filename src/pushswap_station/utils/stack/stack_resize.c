/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:52:59 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 18:13:47 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Create multiply the size of [stack] by 2
 *
 * @return return -1 in case of error;
 */
int	stack_grow(t_stack *stack)
{
	int	i;
	int	*old_list;

	if (stack->capacity == 0)
		return (-1);
	i = 0;
	old_list = stack->content;
	stack->capacity = 2 * stack->capacity;
	stack->content = malloc(stack->capacity * sizeof(int));
	if (stack->content == NULL)
	{
		stack->capacity = 0;
		stack->item_count = 0;
		free(old_list);
		return (1);
	}
	while (i < stack->item_count)
	{
		stack->content[i] = old_list[i];
		i ++;
	}
	free(old_list);
	return (0);
}
