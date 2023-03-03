/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:44:52 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/27 23:52:00 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_is_sorted(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack_first(stack);
	while (i < stack->item_count)
	{
		if (stack->content[i] < max)
			return (0);
		max = stack->content[i];
		i++;
	}
	return (1);
}
