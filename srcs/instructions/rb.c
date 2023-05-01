/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:17:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:55 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_rb(t_tab array)
{
	long	tmp;
	size_t	i;

	tmp = array.stack[0];
	i = 0;
	while (i < *array.size - 1)
	{
		array.stack[i] = array.stack[i + 1];
		i++;
	}
	array.stack[*array.size - 1] = tmp;
	write(STDOUT_FILENO, RB_MSG, ft_strlen(RB_MSG));
}
