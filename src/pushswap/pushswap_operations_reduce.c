/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations_reduce.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 05:39:39 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/25 21:37:26 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_ra_rb(t_operation operation, int *ra_count, int *rb_count);
static void	generate_operations(int ra_count, int rb_count,
				t_stack *reduced_operations);

void	pushswap_operations_reduce(t_pushswap *pushswap)
{
	int		i;
	int		ra_count;
	int		rb_count;
	t_stack	reduced_op;

	i = 0;
	ra_count = 0;
	rb_count = 0;
	reduced_op = stack_create(pushswap->operations_list.capacity,
			pushswap->operations_list.id);
	while (i < pushswap->operations_list.item_count)
	{
		if (count_ra_rb(pushswap->operations_list.content[i],
				&ra_count, &rb_count) != 0)
		{
			generate_operations(ra_count, rb_count, &reduced_op);
			ra_count = 0;
			rb_count = 0;
			stack_add(pushswap->operations_list.content[i], &reduced_op);
		}
		i++;
	}
	generate_operations(ra_count, rb_count, &reduced_op);
	stack_free(&pushswap->operations_list);
	pushswap->operations_list = reduced_op;
}

/**
 * Increment or decrement [ra_count] and [rb_count] in function of [operation]
 *
 * Return 0 if [ra_count] or [rb_count] have been modified
 */
static int	count_ra_rb(t_operation operation, int *ra_count, int *rb_count)
{
	if (operation < ra || operation > rrr)
		return (1);

	if (operation == ra)
		(*ra_count)++;
	else if (operation == rra)
		(*ra_count)--;
	else if (operation == rb)
		(*rb_count)++;
	else if (operation == rrb)
		(*rb_count)--;
	else if (operation == rr)
	{
		(*ra_count)++;
		(*rb_count)++;
	}
	else if (operation == rrr)
	{
		(*ra_count)--;
		(*rb_count)--;
	}
	return (0);
}

static void	generate_operations(int ra_count, int rb_count,
	t_stack *reduced_operations)
{
	int	mutual;

	mutual = 0;
	if (ra_count > 0 && rb_count > 0)
	{
		mutual = ft_min(ra_count, rb_count);
		stack_add_multiple(rr, mutual, reduced_operations);
	}
	else if (ra_count < 0 && rb_count < 0)
	{
		mutual = ft_abs(ft_max(ra_count, rb_count));
		stack_add_multiple(rrr, mutual, reduced_operations);
	}
	ra_count = distance_from_zero_add(ra_count, mutual * (-1));
	rb_count = distance_from_zero_add(rb_count, mutual * (-1));
	if (ra_count < 0)
		stack_add_multiple(rra, ft_abs(ra_count), reduced_operations);
	else
		stack_add_multiple(ra, ft_abs(ra_count), reduced_operations);
	if (rb_count < 0)
		stack_add_multiple(rrb, ft_abs(rb_count), reduced_operations);
	else
		stack_add_multiple(rb, ft_abs(rb_count), reduced_operations);
}
