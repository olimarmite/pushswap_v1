/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:21 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 04:31:57 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "pushswap/pushswap.h"
#include "sorter/sorter.h"

#include "exception_management/exception_management.h"

int	parse_args(int argc, char **argv, t_pushswap *pushswap);

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	pushswap = pushswap_create(argc);
	if (parse_args(argc, argv, &pushswap) != 0)
	{
		pushswap_free(&pushswap);
		return (0);
	}
	sort_main(&pushswap);
	pushswap_operations_print(&pushswap);
	pushswap_free(&pushswap);
	return (0);
}

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
