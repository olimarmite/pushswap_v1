/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:19:07 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:59:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack/stack.h"
# include <stdio.h> //Todo : Forbiden functions
# include <unistd.h>

void	*ft_memmove(int *dest, const int *src, size_t n);
void	ft_putstr_fd(char *str, int fd);

#endif
