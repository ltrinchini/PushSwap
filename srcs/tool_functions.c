/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:10:57 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:25 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_free_all(t_tab a, t_tab b)
{
		free(a.stack);
		free(a.size);
		free(b.stack);
		free(b.size);
}

size_t	ft_size_tab(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	ft_free_tab(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_is_sort(t_tab array)
{
	size_t	i;
	size_t	nb;
	long	tmp;

	nb = 0;
	i = 0;
	while (i < *array.size - 1)
	{
		tmp = array.stack[i];
		if (tmp < array.stack[i + 1])
			nb++;
		i++;
	}
	if (nb == *array.size - 1)
		return (TRUE);
	return (FALSE);
}
