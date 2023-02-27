/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:35:20 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/28 00:45:14 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	read_operations(t_pushswap	*pushswap);
static void	exec_operation(t_operation operation, t_pushswap *pushswap);

int	main(int argc, char **argv)
{
	t_pushswap	pushswap;

	pushswap = pushswap_create(argc);
	if (pushswap.stack_a.capacity == 0 || pushswap.stack_b.capacity == 0
		|| pushswap.operations_list.capacity == 0)
		ft_fatal_error(&pushswap, "Malloc Error");
	if (parse_args(argc, argv, &pushswap) != 0)
	{
		pushswap_free(&pushswap);
		return (0);
	}
	pushswap_index_stack(&pushswap.stack_a);
	stack_print(&pushswap.stack_a);
	read_operations(&pushswap);
	if (stack_is_sorted(&pushswap.stack_a) && pushswap.stack_b.item_count == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	pushswap_free(&pushswap);
	return (0);
}

static void	read_operations(t_pushswap	*pushswap)
{
	char		*line;
	t_operation	parsed_op;

	line = get_next_line(0);
	while (line != 0)
	{
		printf("%s", line);
		parsed_op = parse_operations(line);
		if ((int)parsed_op == -1)
		{
			free(line);
			ft_fatal_error(pushswap, "Invalid Operation");
		}
		else
		{
			exec_operation(parsed_op, pushswap);
		}
		free(line);
		line = get_next_line(0);
	}
	close(fd);
}


static void	exec_operation(t_operation operation, t_pushswap *pushswap)
{
	if (operation == ra || operation == rb)
		pushswap_rotate(0, operation == rb, pushswap);
	else if (operation == rr)
	{
		pushswap_rotate(0, stack_id_a, pushswap);
		pushswap_rotate(0, stack_id_b, pushswap);
	}
	else if (operation == rra || operation == rrb)
		pushswap_rotate(1, operation == rrb, pushswap);
	else if (operation == rrr)
	{
		pushswap_rotate(1, stack_id_a, pushswap);
		pushswap_rotate(1, stack_id_b, pushswap);
	}
	else if (operation == pa || operation == pb)
		pushswap_push(operation == pb, pushswap);
	else if (operation == sa || operation == sb)
		pushswap_swap(operation == sb, pushswap);
	else if (operation == ss)
	{
		pushswap_swap(stack_id_a, pushswap);
		pushswap_swap(stack_id_b, pushswap);
	}
}
