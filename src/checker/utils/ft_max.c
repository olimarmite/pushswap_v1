/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:05:42 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 06:20:33 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Returns the larger of two numbers. [nb_a] [nb_b]
 */
int	ft_max(int nb_a, int nb_b)
{
	if (nb_a > nb_b)
	{
		return (nb_a);
	}
	else
	{
		return (nb_b);
	}
}
