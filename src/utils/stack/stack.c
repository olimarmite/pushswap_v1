/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:55:05 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 02:50:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <string.h>
/**
 * @brief Create empty stack with a maximum [capacity]
 *
 * @return return t_stack or null in case of error
 */
t_stack	stack_create(int capacity)
{
	int		*content;
	t_stack	stack;

	if (capacity > 0)
	{
		content = malloc(capacity* sizeof(int)); //TOTO forbiden function
		if (content)
			content[0] = -1;
	}
	else
	{
		capacity = 0;
		content = NULL;
	}
	stack.capacity = capacity;
	stack.content = content;
	stack.item_count = 0;
	return (stack);
}

/**
 * @brief Add element at the end of [stack]
 *
 * @return return 0 if success;
 */
int	stack_add(int element, t_stack *stack)
{
	if (stack->item_count >= stack->capacity)
		return (1);
	stack->content[stack->item_count] = element;
	stack->item_count ++;
	return (0);
}

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

/**
 * @brief Display [stack] in standard output
 *
 */
void	stack_print(t_stack *stack)
{
	int	i;

	i = 0;
	printf("(%i)[", stack->item_count); // TODO: Forbiden function
	if (stack->item_count >= 1)
	{
		printf("%i", stack->content[i]);
		i++;
	}
	while (i < stack->item_count)
	{
		printf(",%i", stack->content[i]); // TODO: Forbiden function
		i++;
	}
	printf("]"); // TODO: Forbiden function
}
