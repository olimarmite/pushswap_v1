/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:21 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 02:54:50 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int	main(void)
{
	t_stack stack;

	stack = stack_create(6);
	if (stack.capacity == 0)
		return (1);
	// stack_add(5, &stack);
	// stack_add(4, &stack);
	// stack_add(3, &stack);
	// stack_add(2, &stack);
	// stack_add(1, &stack);
	//stack_remove(1, &stack);
	//stack_remove(0, &stack);
	stack_print(&stack);
	printf("\n");
	stack_insert(42, 0, &stack);
	stack_print(&stack);
	return (0);
}
