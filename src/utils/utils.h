/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:19:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/15 05:31:25 by olimarti         ###   ########.fr       */
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

#endif
