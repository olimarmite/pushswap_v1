/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_management.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:59:02 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/14 11:00:39 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_MANAGEMENT_H
# define EXCEPTION_MANAGEMENT_H

# include "../utils/utils.h"
# include "../pushswap/pushswap.h"

void	ft_fatal_error(t_pushswap *pushswap, char *error_msg);
#endif
