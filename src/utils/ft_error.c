/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:27:52 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 10:09:54 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_fatal_error(t_pushswap *pushswap, char *error_msg)
{
	if (error_msg == NULL)
		error_msg = "Error\n";
	pushswap_free(pushswap);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}
