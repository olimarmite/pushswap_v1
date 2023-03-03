/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:23:54 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/03 19:57:29 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	read_operations(t_pushswap	*pushswap)
{
	char		*line;
	t_operation	parsed_op;

	line = get_next_line(0);
	while (line != 0)
	{
		parsed_op = parse_operations(line);
		if ((int)parsed_op == -1)
		{
			free(line);
			get_next_line_close(0);
			ft_fatal_error(pushswap, "Invalid Operation");
		}
		else
		{
			exec_operation(parsed_op, pushswap);
		}
		free(line);
		line = get_next_line(0);
	}
	get_next_line_close(0);
}
