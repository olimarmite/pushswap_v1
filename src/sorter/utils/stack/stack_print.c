/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:02:40 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/28 01:24:55 by olimarti         ###   ########.fr       */
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
	ft_printf("[");
	if (stack->item_count >= 1)
	{
		ft_printf("%i", stack->content[i]);
		i++;
	}
	while (i < stack->item_count)
	{
		ft_printf(",%i", stack->content[i]);
		i++;
	}
	ft_printf("]");
}
