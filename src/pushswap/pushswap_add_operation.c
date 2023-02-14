/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_add_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:19:19 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:19:30 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * Add [operation] to operations
 *
 * Return 0 if success
 * Return -1 if error
 */
int	pushswap_add_operation(t_operation operation, t_pushswap *pushswap)
{
	if (stack_add(operation, &pushswap->operations_list) == 0)
		return (0);
	else
		return (-1);
}

