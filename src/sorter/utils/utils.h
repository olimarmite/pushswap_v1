/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:19:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 09:14:07 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define INT_MAX 2147483647
# include "stack/stack.h"
# include <stdio.h> //Todo : Forbiden functions
# include <unistd.h>

// typedef enum e_status {success, error}	t_status;

// typedef struct s_result
// {
// 	t_status	status;
// 	void		*content;
// }	t_result;

void	*ft_memmove(int *dest, const int *src, size_t n);
void	ft_putstr_fd(char *str, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr, int *nbr);
int		ft_max(int nb_a, int nb_b);
int		ft_min(int nb_a, int nb_b);
int		distance_from_zero_add(int nb_in, int nb_add);
int		ft_abs(int number);

#endif
