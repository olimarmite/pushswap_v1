/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:27:52 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/06 17:58:46 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception_management.h"

void	ft_fatal_error(t_pushswap *pushswap, char *error_msg)
{
	if (error_msg == NULL || USE_BASIC_ERROR != 0)
		error_msg = "Error";
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	pushswap_free(pushswap);
	exit(1);
}
