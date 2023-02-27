/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:07:39 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/26 21:59:27 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../utils/utils.h"

typedef enum e_operation
{
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb,
	sa,
	sb,
	ss
}				t_operation;

typedef enum e_stack_id
{
	stack_id_a,
	stack_id_b
}				t_stack_id;

typedef struct s_pushswap
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			elements_count;
	t_stack		operations_list;
}				t_pushswap;

t_pushswap	pushswap_create(int elements_count);
int			pushswap_rotate(int reverse, t_stack_id stack_id,
				t_pushswap *pushswap);
int			pushswap_swap(t_stack_id stack_id, t_pushswap *pushswap);
int			pushswap_push(t_stack_id to_stack_id, t_pushswap *pushswap);
void		pushswap_free(t_pushswap *pushswap);
int			pushswap_operations_add(t_operation operation,
				t_pushswap *pushswap);
void		pushswap_operations_print(t_pushswap *pushswap);
void		pushswap_index_stack(t_stack *input_stack);
t_stack		*pushswap_stack_from_id(t_stack_id stack_id, t_pushswap *pushswap);
void		pushswap_operations_reduce(t_pushswap *pushswap);
t_pushswap	pushswap_copy(t_pushswap *pushswap_in);

#endif
