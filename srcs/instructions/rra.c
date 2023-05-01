/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:17:53 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:07 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_rra(t_tab array)
{
	int	tmp;
	int	i;

	tmp = array.stack[*array.size - 1];
	i = *array.size - 1;
	while (i > 0)
	{
		array.stack[i] = array.stack[i - 1];
		i--;
	}
	array.stack[i] = tmp;
	write(STDOUT_FILENO, RRA_MSG, ft_strlen(RRA_MSG));
}
