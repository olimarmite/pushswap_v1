/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:35:20 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/03 19:22:37 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	pushswap_index_stack(&pushswap.stack_a);
	read_operations(&pushswap);
	if (stack_is_sorted(&pushswap.stack_a) && pushswap.stack_b.item_count == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	pushswap_free(&pushswap);
	return (0);
}
