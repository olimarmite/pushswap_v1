/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_management.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:59:02 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/27 16:13:19 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_MANAGEMENT_H
# define EXCEPTION_MANAGEMENT_H

# ifndef USE_BASIC_ERROR
#  define USE_BASIC_ERROR 1
# endif

# include "../utils/utils.h"
# include "../pushswap/pushswap.h"

void	ft_fatal_error(t_pushswap *pushswap, char *error_msg);

#endif
