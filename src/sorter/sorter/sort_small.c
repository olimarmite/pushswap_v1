/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:37:23 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/04 04:59:04 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sorter.h"

void	sort_small(t_pushswap *pushswap)
{
	int	i;
	int	moves;

	i = 0;
	moves = 0;
	if (pushswap->stack_a.item_count > 3)
		moves = pushswap->stack_a.item_count / 2;
	while (i++ < moves)
		pushswap_push(stack_id_b, pushswap);
	if ((moves >= 2)
		&& pushswap->stack_b.content[0] < pushswap->stack_b.content[1])
		pushswap_rotate(0, stack_id_b, pushswap);
	if (pushswap->stack_a.item_count >= 3)
	{
		best_goto_index(stack_max_index(&pushswap->stack_a),
			stack_id_a, pushswap);
		if (pushswap->stack_a.content[1] != stack_min(&pushswap->stack_a))
		{
			best_goto_index(1, stack_id_a, pushswap);
			pushswap_swap(stack_id_a, pushswap);
		}
	}
	proximity_sort(pushswap);
	best_goto_index(stack_min_index(&pushswap->stack_a), stack_id_a, pushswap);
}
