/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_multiple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:02:44 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 09:20:03 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Add element [count] time at the end of [stack]
 *
 * @return return 0 if success;
 */
int	stack_add_multiple(int element, int count, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (stack_add(element, stack) != 0)
		{
			return (1);
		}
	}
	return (0);
}
