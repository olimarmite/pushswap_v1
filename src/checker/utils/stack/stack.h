/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:25:08 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/28 00:56:29 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "../utils.h"

typedef struct s_stack {
	int	*content;
	int	capacity;
	int	item_count;
	int	id;
}	t_stack;

t_stack	stack_create(int capacity, int id);
int		stack_add(int element, t_stack *stack);
int		stack_remove(int index, t_stack *stack);
int		stack_insert(int element, int index, t_stack *stack);
int		stack_indexof(int element, t_stack *stack);
void	stack_print(t_stack *stack);
int		stack_first(t_stack *stack);
int		stack_last(t_stack *stack);
int		stack_rotate(int reverse, t_stack *stack);
int		stack_swap(t_stack *stack);
int		stack_push(t_stack *stack, t_stack *toStack);
int		stack_grow(t_stack *stack);
void	stack_free(t_stack *stack);
int		stack_max_index(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_min_index(t_stack *stack);
int		stack_add_multiple(int element, int count, t_stack *stack);
t_stack	stack_copy(t_stack *stack_in);
int		stack_is_sorted(t_stack *stack);

#endif
