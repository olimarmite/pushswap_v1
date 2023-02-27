/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:41:09 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/27 17:42:40 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_args(int argc, char **argv, t_pushswap *pushswap)
{
	int	i;
	int	nb;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i], &nb) == 0)
		{
			if (stack_indexof(nb, &pushswap->stack_a) != -1)
			{
				ft_fatal_error(pushswap,
					"Invalid Arguments\nNumbers must be unique");
				return (2);
			}
			stack_add(nb, &pushswap->stack_a);
		}
		else
		{
			ft_fatal_error(pushswap,
				"Invalid Arguments\nusage example: ./pushswap 1 2 4 8 3");
			return (2);
		}
		i ++;
	}
	return (argc <= 2);
}
