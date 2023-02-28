/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:48:17 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 09:59:23 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	size;

	size = 0;
	while (str[size])
	{
		size ++;
	}
	write(fd, str, size);
}
