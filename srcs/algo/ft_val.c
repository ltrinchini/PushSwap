/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:29:24 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:31 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static int	ft_is_in(long *array, size_t size, long nb)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == nb)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static long	ft_get_min(t_tab array)
{
	long	min;
	size_t	i;

	i = 0;
	min = array.stack[0];
	while (i < *array.size)
	{
		if (min > array.stack[i])
			min = array.stack[i];
		i++;
	}
	return (min);
}

void	ft_push_min(t_tab a, t_tab b)
{
	long	min;

	min = ft_get_min(a);
	if (ft_is_in(a.stack, *a.size / 2, min))
	{
		while (a.stack[0] != min)
			ft_ra(a);
		ft_pb(&a, &b);
		return ;
	}
	while (a.stack[0] != min)
		ft_rra(a);
	ft_pb(&a, &b);
}

long	ft_get_max(long *array, int size)
{
	int		i;
	long	max;

	i = 0;
	max = array[0];
	while (i < size)
	{
		if (max < array[i])
			max = array[i];
		i++;
	}
	return (max);
}
