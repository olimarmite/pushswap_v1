/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:44:25 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 22:39:29 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_pushswap	pushswap_copy(t_pushswap *pushswap_in)
{
	t_pushswap	pushswap_out;

	pushswap_out.stack_a = stack_copy(&pushswap_in->stack_a);
	pushswap_out.stack_b = stack_copy(&pushswap_in->stack_b);
	pushswap_out.operations_list = stack_copy(&pushswap_in->operations_list);
	pushswap_out.elements_count = pushswap_in->elements_count;
	return (pushswap_out);
}
