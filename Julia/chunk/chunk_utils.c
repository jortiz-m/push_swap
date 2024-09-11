/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:18:28 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/11 10:25:00 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	chunk_value(t_stack *stack, t_chunk *chunk, int n)
{
	enum e_loc	loc;
	t_pile		*pile;
	int			i;

	i = 0;
	loc = chunk->loc;
	pile = loc_to_stack(stack, loc);
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

int	chunk_max_value(t_stack *stack, t_chunk *chunk)
{
	t_pile	*pile;
	int		size;
	int		max_value;
	int		i;

	i = 0;
	pile = loc_to_stack(stack, chunk->loc);
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = pile->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = pile->bottom;
	while (size--)
	{
		if (pile->array[i] > max_value)
			max_value = pile->array[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(pile, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(pile, i);
	}
	return (max_value);
}
