/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:36:21 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/27 19:17:57 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_operation	parse_operations(char *line)
{
	int			i;
	static char	*operations[11] = {
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n",
		"pa\n",
		"pb\n",
		"sa\n",
		"sb\n",
		"ss\n"};

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(operations[i], line) == 0)
		{
			return ((t_operation) i);
		}
		i++;
	}
	return (-1);
}
