/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:54:25 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:04:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushswap_free(t_pushswap *pushswap)
{
	free(pushswap->stack_a.content);
	free(pushswap->stack_b.content);
	free(pushswap->operations_list.content);
	pushswap->stack_a.content = NULL;
	pushswap->stack_b.content = NULL;
	pushswap->operations_list.content = NULL;
}
