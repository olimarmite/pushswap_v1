/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:05:42 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 06:21:55 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Returns the lesser of two numbers. [nb_a] [nb_b]
 */
int	ft_min(int nb_a, int nb_b)
{
	if (nb_a < nb_b)
	{
		return (nb_a);
	}
	else
	{
		return (nb_b);
	}
}
