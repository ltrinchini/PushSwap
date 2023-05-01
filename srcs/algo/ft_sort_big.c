/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:35:50 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:25 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static void	ft_tri_help(t_tab a, t_tab b, int elem, long *array)
{
	int		rotate;

	rotate = 0;
	while (elem > 0)
	{
		if (ft_get_max(b.stack, (elem - rotate)) == ft_get_max(array, elem))
		{
			while (b.stack[0] != ft_get_max(array, elem))
			{
				ft_rb(b);
				rotate++;
			}
			ft_pa(&b, &a);
		}
		else
		{
			while (b.stack[0] != ft_get_max(array, elem))
			{
				ft_rrb(b);
				rotate--;
			}
			ft_pa(&b, &a);
		}
		elem--;
	}
}

int	ft_tri(t_tab a, t_tab b, int elements)
{
	int		i;
	long	*array;

	i = -1;
	array = malloc(sizeof(long) * elements);
	if (!array)
		return (EXIT_FAILURE);
	while (++i < elements)
		array[i] = b.stack[i];
	ft_quicksort(array, elements);
	if (elements == 1)
		ft_pa(&b, &a);
	if (elements == 2)
	{
		if (b.stack[0] < b.stack[1])
			ft_sb(b);
		ft_pa(&b, &a);
		ft_pa(&b, &a);
	}
	if (elements > 2)
		ft_tri_help(a, b, elements, array);
	free(array);
	return (EXIT_SUCCESS);
}

static size_t	ft_big_sort_help(t_tab a, t_tab b, size_t rank, long pivot)
{
	size_t	i;

	i = 0;
	while (i < rank && *a.size > 2)
	{
		if (a.stack[0] > a.stack[1])
			ft_sa(a);
		if (a.stack[0] < pivot && *a.size > 2)
		{
			ft_pb(&a, &b);
			i++;
		}
		else if (a.stack[*a.size - 1] <= pivot && *a.size > 2)
			ft_rra(a);
		else if (*a.size > 2)
		{
			while (a.stack[0] >= pivot && *a.size > 2)
				ft_ra(a);
			ft_pb(&a, &b);
			i++;
		}
	}
	return (i);
}

int	ft_big_sort(t_tab a, t_tab b, size_t rank)
{
	int		i;
	long	pivot;

	if (*a.size == 2)
	{
		if (a.stack[0] > a.stack[1])
			ft_sa(a);
		return (EXIT_FAILURE);
	}
	i = 0;
	if (rank > *a.size / 2)
		rank = *a.size / 2;
	else
	{
		pivot = ft_pivot(a.stack, *a.size, rank);
		if (pivot == 2147483648)
			return (EXIT_FAILURE);
		i = ft_big_sort_help(a, b, rank, pivot);
	}
	ft_big_sort(a, b, rank);
	if (ft_tri(a, b, i))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
