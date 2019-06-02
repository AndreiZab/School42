
#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct	s_stack
{
	int			*a;
	int			*b;
	int			len_a;
	int			len_b;
}				t_stack;

void			*del_stack(t_stack *stack);
t_stack			*create_stack(int len);
int				validation_str(char **str);
int				sorted(t_stack *stack);
t_stack			*parse_integers(int len, char **str);
t_stack			*parse_one_str(char *str);

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
