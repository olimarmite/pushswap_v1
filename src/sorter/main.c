/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:21 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/27 17:43:41 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_station.h"

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	pushswap = pushswap_create(argc);
	if (pushswap.stack_a.capacity == 0 || pushswap.stack_b.capacity == 0
		|| pushswap.operations_list.capacity == 0)
		ft_fatal_error(&pushswap, "Malloc Error");
	if (parse_args(argc, argv, &pushswap) != 0)
	{
		pushswap_free(&pushswap);
		return (0);
	}
	if (sort_variator(&pushswap) == -1)
		ft_fatal_error(&pushswap, "Malloc Error - Variator");
	pushswap_operations_print(&pushswap);
	pushswap_free(&pushswap);
	return (0);
}
