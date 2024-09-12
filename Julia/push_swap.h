/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:41:00 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 10:31:39 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdlib.h"
# include "stdbool.h"
# include "limits.h"

enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
};

typedef struct s_chunk
{
	enum eloc	loc;
	int			size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}	t_split_dest;

typedef struct pile
{
	int	*array;
	int	size;
	int	top;
	int	bottom;
}	t_pile;

typedef struct stack
{
	t_pile	a;
	t_pile	b;
	t_list	*op_list;
	bool	writing_mode;
}	t_stack;

void		start_data(t_stack *stacks, int ac, char **av);
char		**process_av(int *ac, char **av);
void		init_pile(t_stack *stacks, t_pile *pile, int ac);
void		fill_pile(t_stack *stacks, t_pile *pile, int ac, char **av);
bool		valid_av(char *av);
void		check_doubles(t_stack *stacks, int *nums, int ac);
void		nums_ranked(int *nums, int *pile, int ac);
bool		is_full(t_pile *pile);
int			current_size(t_pile *pile);
void		error(t_stack *stacks);
void		free_stacks(t_stack *stacks);
void		sort(t_stack *stacks);
bool		is_sorted(t_stack *stacks);
void		sort_three_a(t_stack *stack);
void		sort_five_a(t_stack *stack);
int			next_down(t_pile *pile, int index);
int			next_up(t_pile *pile, int index);
void		chunk_to_the_top(t_stack *stack, t_chunk *to_sort);
int			chunk_value(t_stack *stack, t_chunk *chunk, int n);
t_pile		*loc_to_pile(t_stack *stack, enum e_loc loc);
void		push(t_pile *src, t_pile *dest);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
void		r_rotate(t_pile *pile);
void		r_rotate_a(t_stack *stack);
void		r_rotate_b(t_stack *stack);
void		r_rotate_ab(t_stack *stack);
void		rotate(t_pile *pile);
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rotate_ab(t_stack *stack);
void		swap(t_pile *pile);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_ab(t_stack *stack);
void		save_op(t_stack *stack, enum e_op op);
void		show_moves(t_list *head);
const char	*op_to_string(enum e_op op);
enum e_op	op_from(t_list *node);
int			move_from_to(t_stack *stack, enum e_loc from, enum e_loc to);
void		move_from_top_a(t_stack *stack, enum e_loc to);
void		move_from_top_b(t_stack *stack, enum e_loc to);
void		move_from_bottom_a(t_stack *stack, enum e_loc to);
void		move_from_bottom_b(t_stack *stack, enum eloc to);
void		chunk_sort(t_stack *stack);
void		rec_chunk_sort(t_stack *stack, t_chunk *to_sort);
void		sort_two(t_stack *stack, t_chunk *to_sort);
void		sort_one(t_stack *stack, t_chunk *to_sort);
void		chunk_split(t_ps *stack, t_chunk *to_split, t_split_dest *dest);
void		split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max);
t_stack		*loc_to_stack(t_stack *stacks, enum e_loc loc);
void		set_pivots(enum e_loc loc, int crt_size, int *pvt_1, int *pvt_2);
int			chunk_value(t_stack *stack, t_chunk *chunk, int n);
int			chunk_max_value(t_stack *stack, t_chunk *chunk);

#endif