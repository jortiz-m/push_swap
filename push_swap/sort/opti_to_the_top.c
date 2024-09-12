/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_to_the_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:24 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 10:33:09 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&stack->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&stack->a) == to_sort->size)
		to_sort->loc = TOP_A;
}

int	chunk_value(t_stack *stack, t_chunk *chunk, int n) /*Revisar esta, 
es similar a la funcion value*/
{
	enum e_loc	loc;
	t_pile		*pile;
	int			i;

	loc = chunk->loc;
	pile = loc_to_pile(stack, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = pile->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = pile->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = next_down(pile, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(pile, i);
	return (pile->array[i]);
}

t_pile	*loc_to_pile(t_stack *stack, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&stack->a);
	else
		return (&stack->b);
}
