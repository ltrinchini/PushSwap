/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:31:37 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:58:55 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static long	*ft_atol_tab(char **array, size_t size_tab, int (*ptr)(char *))
{
	size_t	i;
	long	*dst;

	i = 0;
	dst = malloc(sizeof(long) * size_tab);
	if (!dst)
		return (NULL);
	while (i < size_tab)
	{
		if ((*ptr)(array[i]))
		{
			free(dst);
			write(STDERR_FILENO, ERR_MSG, ft_strlen(ERR_MSG));
			return (NULL);
		}
		dst[i] = ft_atol(array[i]);
		i++;
	}
	return (dst);
}

static long	*ft_init_from_list(char **av, size_t *ptr_size)
{
	char	**tab_char;
	int		size_tab;
	long	*dst;
	int		(*ft_ptr)(char *);

	if (!ft_strlen(av[1]))
		return (NULL);
	ft_ptr = &ft_check_list;
	tab_char = ft_split(av[1], ' ');
	if (!tab_char)
		return (NULL);
	size_tab = ft_size_tab(tab_char);
	*ptr_size = size_tab;
	dst = ft_atol_tab(tab_char, size_tab, ft_ptr);
	if (!dst)
	{
		ft_free_tab(tab_char, size_tab);
		return (NULL);
	}
	ft_free_tab(tab_char, size_tab);
	if (ft_check_final(dst, size_tab))
		return (NULL);
	return (dst);
}

static long	*ft_init_from_arg(int ac, char **av, size_t *ptr_size)
{
	long	*dst;
	int		size_tab;
	int		(*ft_ptr)(char *);

	size_tab = ac - 1;
	*ptr_size = size_tab;
	ft_ptr = &ft_check_arg;
	dst = ft_atol_tab(&av[1], ac - 1, (*ft_ptr));
	if (!dst)
		return (NULL);
	if (ft_check_final(dst, size_tab))
		return (NULL);
	return (dst);
}

static long	*ft_init_tab(int ac, char **av, size_t *ptr_size)
{
	long		*dst;

	if (ac < 2)
		return (NULL);
	else if (ac == 2)
	{
		dst = ft_init_from_list(av, ptr_size);
		if (!dst)
			return (NULL);
	}
	if (ac > 2)
	{
		dst = ft_init_from_arg(ac, av, ptr_size);
		if (!dst)
			return (NULL);
	}
	return (dst);
}

void	ft_init(int ac, char **av, t_tab *a, t_tab *b)
{
	size_t	size;

	size = 0;
	a->size = malloc(sizeof(size_t));
	b->size = malloc(sizeof(size_t));
	a->stack = ft_init_tab(ac, av, &size);
	if (!a->stack)
		return ;
	*a->size = size;
	b->stack = ft_init_tab(ac, av, &size);
	if (!b->stack)
	{
		free(a->stack);
		return ;
	}
	*b->size = 0;
}
