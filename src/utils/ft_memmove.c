/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:51:41 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/13 02:49:45 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>


void	*ft_memmove(int *dest, const int *src, size_t n)
{
	size_t	i;
	int	*d;

	d = dest;
	if ((dest == NULL && src == NULL))
		return (NULL);
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			d[i] = ((const int *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = ((const int *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
