/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:44:13 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/06 12:53:12 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_pile *src, t_pile *dest)
{
	int	dest_index;

	if (is_full(dest))
		return ;
	dest_index = next_up(dest, dest->top);
	dest->array[dest_index] = src->array[src->top];
	dest->top = dest_index;
	src->array[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_stack *stack)
{
	push(&stack->a, &stack->b);
}

void	push_b(t_stack *stack)
{
	push(&stack->b, &stack->a);
}
