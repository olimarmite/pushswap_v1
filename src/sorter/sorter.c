/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:07:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/21 05:04:02 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_main(t_pushswap *pushswap)
{
	presort(8, pushswap);
	return (0);
}

void	presort(int chunk_count, t_pushswap *pushswap)
{
	int	i;

	i = 1;
	(void) chunk_count;
	while (i < pushswap->elements_count)
	{
		if (stack_first(&pushswap->stack_a) < 250)
		{
			pushswap_push(stack_id_b, pushswap);
		}
		else
		{
			pushswap_rotate(0, stack_id_a, pushswap);
		}
		i++;
	}
}
