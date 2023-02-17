/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:54:25 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/17 08:49:38 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushswap_free(t_pushswap *pushswap)
{
	stack_free(&pushswap->stack_a);
	stack_free(&pushswap->stack_b);
	stack_free(&pushswap->operations_list);
}
