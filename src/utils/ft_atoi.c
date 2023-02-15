/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:55:39 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/15 05:32:12 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


/**
 * Convert String [nptr] formated number to int
 *
 * @param nptr Input String
 * @param nbr Output pointer
 * @return Return 1 if [nptr] is a valid number
 */
int	ft_atoi(const char *nptr, int *nbr)
{
	long	nb;
	size_t	i;

	nb = 0;
	i = 0;
	*nbr = 0;
	if (*nptr == '-' || *nptr == '+')
		i++;
	while ((nptr[i] != 0))
	{
		if (ft_isdigit(nptr[i]) != 1)
			return (0);
		else
		{
			nb = nb * 10 + (nptr[i] - '0');
			if (nb > INT_MAX + (*nptr == '-'))
				return (0);
			i++;
		}
	}
	if (*nptr == '-')
		nb *= -1;
	*nbr = nb;
	return (1);
}
