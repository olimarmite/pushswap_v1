/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:21 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:07:21 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "pushswap/pushswap.h"

int	main(void)
{
	t_pushswap	pushswap;

	pushswap = pushswap_create(10);
	stack_add(1, &pushswap.stack_a);
	stack_add(2, &pushswap.stack_a);
	stack_add(3, &pushswap.stack_a);
	stack_add(4, &pushswap.stack_a);
	stack_add(5, &pushswap.stack_a);
	stack_print(&pushswap.stack_a);
	pushswap_rotate(1, stack_id_a, &pushswap);
	stack_print(&pushswap.stack_a);
	pushswap_push(stack_id_a, &pushswap);
	stack_print(&pushswap.stack_a);
	stack_print(&pushswap.stack_b);
	//ft_fatal_error(&pushswap, NULL);
	pushswap_free(&pushswap);
	return (0);
}
