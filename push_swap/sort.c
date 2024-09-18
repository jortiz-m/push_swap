/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:49:25 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/18 10:49:28 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value(t_pile *pile, int n)
{
	int	i;

	i = pile->top;
	while (--n > 0)
		i = next_down(pile, i);
	return (pile->array[i]);
}

void	sort(t_stack *stacks)
{
	if (is_sorted(stacks))
		return ;
	else if (stacks->a.size == 3)
		sort_three_a(stacks);
	else if (stacks->a.size == 5)
		sort_five_a(stacks);
	else
		chunk_sort(stacks);
}

void	sort_three_a(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = value(&stack->a, 1);
	second = value(&stack->a, 2);
	third = value(&stack->a, 3);
	if (first > second && third > second && third > first)
		swap_a(stack);
	else if (first > second && third > second && first > third)
		rotate_a(stack);
	else if (second > first && second > third && first > third)
		r_rotate_a(stack);
	else if (second > first && second > third && third > first)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (first > second && second > third && first > third)
	{
		swap_a(stack);
		r_rotate_a(stack);
	}
}

void	sort_five_a(t_stack *stack)
{
	while (current_size(&stack->a) > 3)
	{
		if (value(&stack->a, 1) == 1 || value(&stack->a, 1) == 2)
			push_b(stack);
		else
			rotate_a(stack);
	}
	if (value(&stack->b, 1) < value(&stack->b, 2))
		swap_b(stack);
	sort_three_a(stack);
	push_a(stack);
	push_a(stack);
}
