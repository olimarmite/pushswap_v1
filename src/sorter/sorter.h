/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 02:06:57 by olimarti          #+#    #+#             */
/*   Updated: 2023/02/21 03:11:32 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORTER_H
# define SORTER_H

# include "../utils/utils.h"
# include "../pushswap/pushswap.h"

int	sort_main(t_pushswap *pushswap);
void	presort(int chunk_count, t_pushswap *pushswap);

#endif
