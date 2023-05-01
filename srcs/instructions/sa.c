/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:15:18 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:18 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_sa(t_tab array)
{
	int	tmp;

	if (*array.size < 2)
		return ;
	tmp = array.stack[0];
	array.stack[0] = array.stack[1];
	array.stack[1] = tmp;
	write(STDOUT_FILENO, SA_MSG, ft_strlen(SA_MSG));
}
