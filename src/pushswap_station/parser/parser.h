/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:41:34 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/27 17:43:07 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../utils/utils.h"
# include "../pushswap/pushswap.h"
# include "../exception_management/exception_management.h"

int	parse_args(int argc, char **argv, t_pushswap *pushswap);

#endif
