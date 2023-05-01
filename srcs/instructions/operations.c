/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:04:33 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:40 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_swap(t_tab array)
{
	long	tmp;

	if (*array.size < 2)
		return ;
	tmp = array.stack[0];
	array.stack[0] = array.stack[1];
	array.stack[1] = tmp;
}

void	ft_rotate(t_tab array)
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
}

void	ft_reverse_rotate(t_tab array)
{
	long	tmp;
	size_t	i;

	tmp = array.stack[*array.size - 1];
	i = *array.size - 1;
	while (i > 0)
	{
		array.stack[i] = array.stack[i - 1];
		i--;
	}
	array.stack[i] = tmp;
}

void	ft_push(t_tab *tab1, t_tab *tab2)
{
	if (*tab1->size == 0)
		return ;
	*tab2->size += 1;
	ft_reverse_rotate(*tab2);
	tab2->stack[0] = tab1->stack[0];
	ft_rotate(*tab1);
	*tab1->size -= 1;
}
