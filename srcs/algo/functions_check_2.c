/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_check_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:30:01 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:36 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

int	ft_check_alpha(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isnum(str[i]) && !(str[i] == '-') && !(str[i] == ' '))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_minus_sign(char *str)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '-')
			nb++;
		i++;
	}
	if ((nb == 1 && str[0] != '-') || nb > 1
		|| (nb == 1 && ft_strlen(str) == 1))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
