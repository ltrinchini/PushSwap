/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:20:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:56:58 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_push_swap(int ac, char **av)
{
	t_tab	a;
	t_tab	b;

	ft_init(ac, av, &a, &b);
	if ((!a.stack || !b.stack) || (ft_is_sort(a)))
	{
		ft_free_all(a, b);
		return (EXIT_FAILURE);
	}
	if (*a.size == 2)
		ft_sort_two(a);
	else if (*a.size == 3)
		ft_sort_three(a);
	else if (*a.size <= 10) {
		ft_sort_ten(a, b);
	}
	else if (*a.size > 10 && *a.size <= 100)
	{
		if (ft_big_sort(a, b, *a.size / 6))
		{
			ft_free_all(a, b);
			return (EXIT_FAILURE);
		}
	}
	else if (*a.size > 100)
	{
		if (ft_big_sort(a, b, *a.size / 12))
		{
			ft_free_all(a, b);
			return (EXIT_FAILURE);
		}
	}
	ft_free_all(a, b);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	return (ft_push_swap(ac, av));
}
