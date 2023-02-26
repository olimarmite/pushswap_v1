/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_variator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:41:38 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 22:49:02 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_variator(t_pushswap *pushswap)
{
	int			i;
	int			best_cost;
	int			best_chunk_mod;
	t_pushswap	pushswap_tmp;

	i = 0;
	while (i < 20)
	{
		pushswap_tmp = pushswap_copy(pushswap);
		if (pushswap_tmp.stack_a.capacity == 0
			|| pushswap_tmp.stack_b.capacity == 0
			|| pushswap_tmp.operations_list.capacity == 0)
		{
			pushswap_free(&pushswap_tmp);
			return (-1);
		}
		sort_main(&pushswap_tmp, i);
		printf("-%d-", pushswap_tmp.operations_list.item_count);
		if (i == 0 || pushswap_tmp.operations_list.item_count < best_cost)
		{
			best_cost = pushswap_tmp.operations_list.item_count;
			best_chunk_mod = i;
		}
		pushswap_free(&pushswap_tmp);
		i++;
	}
	sort_main(pushswap, best_chunk_mod);
	printf("\n _%d_ \n", pushswap->operations_list.item_count);
	return (0);
}
