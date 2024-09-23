/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:46:18 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/23 10:04:54 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile)
{
	if (is_full(pile))
	{
		pile->bottom = pile->top;
		pile->top = next_down(pile, pile->top);
	}
	else
	{
		pile->bottom = next_down(pile, pile->bottom);
		pile->array[pile->bottom] = pile->array[pile->top];
		pile->array[pile->top] = 0;
		pile->top = next_down(pile, pile->top);
	}
}

void	rotate_a(t_stack *stack)
{
	rotate(&stack->a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	rotate(&stack->b);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	ft_printf("rr\n");
}
