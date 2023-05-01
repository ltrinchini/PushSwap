/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:26:50 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:33 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static int	ft_check_doublon(long *array, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_list(char *tab_char)
{
	if (ft_check_minus_sign(tab_char) || ft_check_alpha(tab_char))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_check_arg(char *tab_char)
{
	if (ft_check_minus_sign(tab_char) || ft_check_alpha(tab_char)
		|| (ft_strlen(tab_char) == 0) || ft_check_space(tab_char))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_lim_int(long *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (array[i] > INT32_MAX || array[i] < INT32_MIN)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_final(long *dst, int size_tab)
{
	if (ft_check_doublon(dst, size_tab)
		|| ft_check_lim_int(dst, size_tab))
	{
		if (dst)
			free(dst);
		write(STDERR_FILENO, ERR_MSG, ft_strlen(ERR_MSG));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
