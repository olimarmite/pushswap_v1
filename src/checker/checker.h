/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:10 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/03 19:31:46 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line/get_next_line.h"
# include "../pushswap_station/pushswap_station.h"

t_operation	parse_operations(char *line);
void		exec_operation(t_operation operation, t_pushswap *pushswap);
void		read_operations(t_pushswap	*pushswap);

#endif
