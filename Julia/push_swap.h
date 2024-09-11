/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:41:00 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/11 11:02:30 by jortiz-m         ###   ########.fr       */
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
}

typedef struct s_chunk
{
	enum e_loc loc;
	int			size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
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

void	init_stacks(t_stack *stacks, int ac, char **av, bool writing_mode);

void	fill_pile(t_stack *stacks, t_pile *piles, int ac, char **av);
bool	valid_av(char av*);
void	check_doubles(t_stack *stacks, int *nums, int ac);
void	nums_ranked(t_stack *stacks, int *nums, int ac);
bool	is_full(t_pile *pile);

void	error(t_stack *stacks);

void	sort(t_stack *stacks);

int		next_down(t_pile *pile, int index);
int		next_up(t_pile *pile, int index);

void	push(t_pile *src, t_pile *dest);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);

void	rotate(t_pile *pile);
void	rotate_a(t_pile *pile);
void	rotate_b(t_pile *pile);
void	rotate_ab(t_pile *pile);

void	r_rotate(t_pile *pile);
void	r_rotate_a(t_stack *stack);
void	r_rotate_b(t_stack *stack);
void	r_rotate_ab(t_stack *stack);

void	swap(t_pile *pile);
void	swap_a(t_pile *pile);
void	swap_b(t_pile *pile);
void	swap_ab(t_pile *pile);

void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort);

void	chunk_sort(t_stack *stack);
#endif