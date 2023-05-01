/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:19:06 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:49 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_pb(t_tab *tab1, t_tab *tab2)
{
	if (*tab1->size == 0)
		return ;
	(*tab2->size)++;
	ft_reverse_rotate(*tab2);
	tab2->stack[0] = tab1->stack[0];
	ft_rotate(*tab1);
	(*tab1->size)--;
	write(STDOUT_FILENO, PB_MSG, ft_strlen(PB_MSG));
}
