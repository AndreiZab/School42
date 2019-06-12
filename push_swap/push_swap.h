/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:27:35 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/10 12:42:50 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define LYELLOW "\x1b[93m"
# define NO_C "\x1b[0m"

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			len_a;
	int			len_b;
	int			v;
}				t_stack;

int				del_stack(t_stack *stack);
t_stack			*create_stack(int len);
void			print_v(t_stack *stack, char *str);
int				validation_str(char **str, int len);
int				sorted(t_stack *stack);
t_stack			*parse_integers(int len, char **str, int v);
void			parse_instructions(t_stack *stack);
t_stack			*parse_one_str(char *str, int v);
int				ft_median(int *array, int len);
int				ft_duplicates(int *array, int len);
int				compare(int a, int b, int c);
void			hard_sort(t_stack *stack, int max);
void			soft_sort(t_stack *stack);
void			sort_2_element(t_stack *stack, char ar);
void			sort_3_element(t_stack *stack, char s);
void			do_swap(t_stack *stack, char s);
void			ft_swap(int *x, int *y);
void			quick_sort(int *list, int min, int max);
void			gnl(t_stack *stack, char *line);
int				*ft_reverce(int *ar, size_t n);
int				split_a(t_stack *stack);
int				split_b(t_stack *stack);
void			over_sort(t_stack *stack, int max);
void			sort_3_elemnt(t_stack *stack, char s);

void			do_ss(t_stack *stack, int print);
void			do_sa(t_stack *stack, int print);
void			do_sb(t_stack *stack, int print);
void			do_pb(t_stack *stack, int print);
void			do_pa(t_stack *stack, int print);
void			do_ra(t_stack *stack, int print);
void			do_rb(t_stack *stack, int print);
void			do_rr(t_stack *stack, int print);
void			do_rrb(t_stack *stack, int print);
void			do_rra(t_stack *stack, int print);
void			do_rrr(t_stack *stack, int print);

#endif
