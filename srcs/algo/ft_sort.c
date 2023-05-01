/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:15:10 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:28 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

void	ft_quicksort(long *tableau, int size)
{
	long	wall;
	int		i;
	long	pivot;
	long	tmp;

	if (size < 2)
		return ;
	pivot = tableau[size - 1];
	wall = 0;
	i = -1;
	while (++i < size)
	{
		if (tableau[i] <= pivot)
		{
			if (wall != i)
			{
				tmp = tableau[i];
				tableau[i] = tableau[wall];
				tableau[wall] = tmp;
			}
			wall++;
		}
	}
	ft_quicksort(tableau, wall - 1);
	ft_quicksort(&tableau[wall - 1], size - wall + 1);
}

long	ft_pivot(long *array, int lenght, int rank)
{
	int		i;
	long	*tab_stillborn;
	long	pivot;

	i = 0;
	tab_stillborn = malloc(sizeof(long) * lenght);
	if (!tab_stillborn)
		return (2147483648L);
	if (rank >= lenght)
		rank = lenght - 1;
	while (i < lenght)
	{
		tab_stillborn[i] = array[i];
		i++;
	}
	ft_quicksort(tab_stillborn, lenght);
	pivot = tab_stillborn[rank];
	free(tab_stillborn);
	return (pivot);
}

void	ft_sort_two(t_tab array)
{
	if (array.stack[0] > array.stack[1])
		ft_sa(array);
}

void	ft_sort_three(t_tab array)
{
	if (array.stack[0] > array.stack[1] && array.stack[1] > array.stack[2])
	{
		ft_ra(array);
		ft_sa(array);
	}
	else if (array.stack[0] < array.stack[1] && array.stack[1] > array.stack[2]
		&& array.stack[0] < array.stack[2])
	{
		ft_sa(array);
		ft_ra(array);
	}
	else if (array.stack[0] > array.stack[1] && array.stack[1] < array.stack[2]
		&& array.stack[0] < array.stack[2])
		ft_sa(array);
	else if (array.stack[0] < array.stack[1] && array.stack[1] > array.stack[2]
		&& array.stack[0] > array.stack[2])
		ft_rra(array);
	else if (array.stack[0] > array.stack[1] && array.stack[1] < array.stack[2]
		&& array.stack[0] > array.stack[2])
		ft_ra(array);
}

void	ft_sort_ten(t_tab a, t_tab b)
{
	while (*a.size > 3)
		ft_push_min(a, b);
	ft_sort_three(a);
	while (*b.size > 0)
		ft_pa(&b, &a);
}
