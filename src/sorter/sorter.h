/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:06:57 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 09:25:11 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORTER_H
# define SORTER_H

# include "../utils/utils.h"
# include "../pushswap/pushswap.h"

typedef struct s_chunk
{
	int	min;
	int	max;
}	t_chunk;

typedef struct s_move
{
	int	index_a;
	int	index_b;
}	t_move;

int		sort_main(t_pushswap *pushswap);
void	presort(int chunk_count, t_pushswap *pushswap);
void	move_two_chunks(t_chunk chunk_a, t_chunk chunk_b, t_pushswap *pushswap);
t_move	get_t_move(int index_a, int index_b);
int		calc_move_to_a_cost(
			t_move move,
			int reverse_a,
			int reverse_b,
			t_pushswap *pushswap);
int		proximity_sort(t_pushswap *pushswap);
int		double_goto_index(t_move move, t_pushswap *pushswap);
void	goto_index(int index, int reverse,
			t_stack_id stack_id, t_pushswap *pushswap);
int		double_goto_best_move(t_move move, t_pushswap *pushswap);

#endif
