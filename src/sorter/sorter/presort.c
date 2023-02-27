/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:52:22 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/28 00:53:55 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	presort(int chunk_count, t_pushswap *pushswap)
{
	int		chunk_size;
	t_chunk	chunk_a;
	t_chunk	chunk_b;

	if (pushswap->stack_a.item_count <= chunk_count)
	{
		chunk_count = 2;//pushswap->stack_a.item_count;
	}
	chunk_size = pushswap->stack_a.item_count / chunk_count;
	chunk_a.max = pushswap->stack_a.item_count / 2;
	chunk_a.min = chunk_a.max - chunk_size;
	chunk_b.min = pushswap->stack_a.item_count / 2;
	chunk_b.max = chunk_b.min + chunk_size;
	while (pushswap->stack_a.item_count > 0)
	{
		move_two_chunks(chunk_b, chunk_a, pushswap);
		chunk_a.max = chunk_a.min;
		chunk_a.min -= chunk_size;
		chunk_b.min = chunk_b.max;
		chunk_b.max += chunk_size;
	}
}

void	move_two_chunks(t_chunk chunk_a, t_chunk chunk_b, t_pushswap *pushswap)
{
	int	i;
	int	len;

	i = 0;
	len = pushswap->stack_a.item_count;
	while (i < len)
	{
		if (((stack_first(&pushswap->stack_a) >= chunk_a.min)
				&& (stack_first(&pushswap->stack_a) <= chunk_a.max)))
		{
			pushswap_push(stack_id_b, pushswap);
		}
		else if (((stack_first(&pushswap->stack_a) >= chunk_b.min)
				&& (stack_first(&pushswap->stack_a) <= chunk_b.max)))
		{
			pushswap_push(stack_id_b, pushswap);
			pushswap_rotate(0, stack_id_b, pushswap);
		}
		else
		{
			pushswap_rotate(0, stack_id_a, pushswap);
		}
		i++;
	}
}
