/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:23:42 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/03 19:24:23 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	exec_operation(t_operation operation, t_pushswap *pushswap)
{
	if (operation == ra || operation == rb)
		pushswap_rotate(0, operation == rb, pushswap);
	else if (operation == rr)
	{
		pushswap_rotate(0, stack_id_a, pushswap);
		pushswap_rotate(0, stack_id_b, pushswap);
	}
	else if (operation == rra || operation == rrb)
		pushswap_rotate(1, operation == rrb, pushswap);
	else if (operation == rrr)
	{
		pushswap_rotate(1, stack_id_a, pushswap);
		pushswap_rotate(1, stack_id_b, pushswap);
	}
	else if (operation == pa || operation == pb)
		pushswap_push(operation == pb, pushswap);
	else if (operation == sa || operation == sb)
		pushswap_swap(operation == sb, pushswap);
	else if (operation == ss)
	{
		pushswap_swap(stack_id_a, pushswap);
		pushswap_swap(stack_id_b, pushswap);
	}
}
