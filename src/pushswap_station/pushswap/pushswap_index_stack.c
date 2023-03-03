/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_index_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:30:16 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/17 08:42:33 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushswap_index_stack(t_stack *input_stack)
{
	t_stack	output_stack;
	int		smaller_items_count;
	int		i;
	int		j;

	output_stack = stack_create(input_stack->capacity, input_stack->id);
	i = 0;
	while (i < input_stack->item_count)
	{
		smaller_items_count = 0;
		j = 0;
		while (j < input_stack->item_count)
		{
			if (input_stack->content[j] < input_stack->content[i])
			{
				smaller_items_count ++;
			}
			j++;
		}
		stack_add(smaller_items_count, &output_stack);
		i++;
	}
	stack_free(input_stack);
	*input_stack = output_stack;
}
