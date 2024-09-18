/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:48:36 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/18 10:48:55 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_pile *pile)
{
	if (is_full(pile))
	{
		pile->top = pile->bottom;
		pile->bottom = next_up(pile, pile->bottom);
	}
	else
	{
		pile->top = next_up(pile, pile->top);
		pile->array[pile->top] = pile->array[pile->bottom];
		pile->array[pile->bottom] = 0;
		pile->bottom = next_up(pile, pile->bottom);
	}
}

void	r_rotate_a(t_stack *stack)
{
	r_rotate(&stack->a);
	save_op(stack, rra);
}

void	r_rotate_b(t_stack *stack)
{
	r_rotate(&stack->b);
	save_op(stack, rrb);
}

void	r_rotate_ab(t_stack *stack)
{
	r_rotate(&stack->a);
	r_rotate(&stack->b);
	save_op(stack, rrr);
}
