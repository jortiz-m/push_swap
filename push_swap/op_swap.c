/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:16:09 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/18 10:07:48 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile)
{
	int	tmp;

	if (pile->array[next_down(pile, pile->top)] == 0)
		return ;
	tmp = pile->array[pile->top];
	pile->array[pile->top] = pile->array[next_down(pile, pile->top)];
	pile->array[next_down(pile, pile->top)] = tmp;
}

void	swap_a(t_stack *stack)
{
	swap(&stack->a);
	save_op(stack, sa);
}

void	swap_b(t_stack *stack)
{
	swap(&stack->b);
	save_op(stack, sb);
}

void	swap_ab(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	save_op(stack, ss);
}
