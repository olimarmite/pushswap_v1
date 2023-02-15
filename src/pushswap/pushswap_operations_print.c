/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations_print.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:55:14 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/15 05:30:35 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	*operation_to_str(t_operation operation);

/**
 * @brief Display [stack] in standard output
 *
 */
void	pushswap_operations_print(t_pushswap *pushswap)
{
	int	i;

	i = 0;
	while (i < pushswap->operations_list.item_count)
	{
		ft_putstr_fd(operation_to_str(pushswap->operations_list.content[i]), 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

/**
 * Return String representation of [operation]
 *
 * Return "UNKNOWN OPERATION" if operation is invalid
 */
static char	*operation_to_str(t_operation operation)
{
	static char	*lookup_table[] = {
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
		"pa",
		"pb",
		"sa",
		"sb",
		"ss"};

	if (operation >= 0 && operation <= 10)
		return (lookup_table[operation]);
	else
		return ("UNKNOWN OPERATION");
}
