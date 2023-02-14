/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:02:40 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 03:03:05 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Display [stack] in standard output
 *
 */
void	stack_print(t_stack *stack)
{
	int	i;

	i = 0;
	printf("["); // TODO: Forbiden function
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
