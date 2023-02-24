/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_from_zero_add.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:40:19 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/24 08:43:13 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	distance_from_zero_add(int nb_in, int nb_add)
{
	if (nb_in < 0)
	{
		nb_in -= nb_add;
	}
	else
	{
		nb_in += nb_add;
	}
	return (nb_in);
}
