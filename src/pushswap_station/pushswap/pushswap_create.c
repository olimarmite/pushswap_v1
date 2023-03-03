/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:21:25 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:19:47 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_pushswap	pushswap_create(int elements_count)
{
	t_pushswap	pushswap;
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a = stack_create(elements_count + 1, stack_id_a);
	stack_b = stack_create(elements_count + 1, stack_id_b);
	pushswap.elements_count = elements_count;
	pushswap.stack_a = stack_a;
	pushswap.stack_b = stack_b;
	pushswap.operations_list = stack_create(5500, 3);
	return (pushswap);
}
