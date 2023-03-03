/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations_add.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:19:19 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/17 10:29:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * Add [operation] to operations
 *
 * Return 0 if success
 * Return -1 if error
 */
int	pushswap_operations_add(t_operation operation, t_pushswap *pushswap)
{
	if (stack_add(operation, &pushswap->operations_list) == 0)
		return (0);
	else
		return (-1);
}
