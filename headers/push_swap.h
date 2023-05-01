/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchini <ltrinchini@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:18:23 by ltrinchi          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:17 by ltrinchini       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/srcs/libft.h"

# define PA_MSG "pa\n"
# define PB_MSG "pb\n"
# define RA_MSG "ra\n"
# define RB_MSG "rb\n"
# define RRA_MSG "rra\n"
# define RRB_MSG "rrb\n"
# define SA_MSG "sa\n"
# define SB_MSG "sb\n"
# define ERR_MSG "Error\n"
# define TRUE 1
# define FALSE 0

typedef struct s_tab
{
	long	*stack;
	size_t	*size;
}	t_tab;


//Tools functions
void		ft_free_all(t_tab a, t_tab b);
int			ft_is_sort(t_tab array);

//Functions check and init
void		ft_init(int ac, char **av, t_tab *a, t_tab *b);
size_t		ft_size_tab(char **array);
int			ft_check_list(char *tab_char);
int			ft_check_arg(char *tab_char);
int			ft_check_final(long *dst, int size_tab);
int			ft_check_alpha(char *str);
int			ft_check_space(char *str);
int			ft_check_minus_sign(char *str);
void		ft_free_tab(char **array, int size);

//Operations
void		ft_pa(t_tab *tab1, t_tab *tab2);
void		ft_pb(t_tab *tab1, t_tab *tab2);
void		ft_ra(t_tab array);
void		ft_rb(t_tab array);
void		ft_rra(t_tab array);
void		ft_rrb(t_tab array);
void		ft_sa(t_tab array);
void		ft_sb(t_tab array);
void		ft_swap(t_tab array);
void		ft_rotate(t_tab array);
void		ft_reverse_rotate(t_tab array);
void		ft_push(t_tab *tab1, t_tab *tab2);

//Algo
long		ft_get_max(long *array, int size);
void		ft_push_min(t_tab a, t_tab b);
void		ft_sort_two(t_tab array);
void		ft_sort_three(t_tab array);
void		ft_sort_ten(t_tab a, t_tab b);
void		ft_quicksort(long *tableau, int size);
long		ft_pivot(long *array, int lenght, int rank);
int			ft_tri(t_tab a, t_tab b, int elements);
int			ft_big_sort(t_tab a, t_tab b, size_t rank);

int			ft_push_swap(int ac, char **av);

#endif
