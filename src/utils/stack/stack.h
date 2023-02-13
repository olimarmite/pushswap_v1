/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:25:08 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 00:07:40 by olimarti         ###   ########.fr       */
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
}	t_stack;

t_stack	stack_create(int capacity);
int		stack_add(int element, t_stack *stack);
int		stack_remove(int index, t_stack *stack);
int		stack_insert(int element, int index, t_stack *stack);
int		stack_indexof(int element, t_stack *stack);
void	stack_print(t_stack *stack);

#endif
