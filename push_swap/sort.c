/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 10:33:15 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stacks)
{
	if (stacks->a.size <= 1 || is_sorted(stacks))
		return ;
	else if (stacks->a.size == 3)
		sort_three_a(stacks);
	else if (stacks->a.size == 5)
		sort_five_a(stacks);
	else
		chunk_sort(stacks);
}

bool	is_sorted(t_stack *stacks)
{
	int	i;
	int	rank;

	i = 0;
	rank = 1;
	while (rank <= stacks->a.size)
	{
		if (stacks->a.array[i] != rank)
			return (false);
		rank++;
		i = next_down(&stacks->a, i);
	}
	return (true);
}

void	sort_three_a(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a.array[0];
	second = stack->a.array[1];
	third = stack->a.array[2];
	if (first > second && third > second && third > first)
		swap_a(&stack->a);
	else if (first > second && third > second && first > third)
		rotate_a(&stack->a);
	else if (second > first && second > third && first > third)
		r_rotate_a(&stack->a);
	else if (second > first && second > third && third > first)
	{
		swap_a(&stack->a);
		rotate_a(&stack->a);
	}
	else if (first > second && second > third && first > third)
	{
		rotate_a(&stack->a);
		swap_a(&stack->a);
	}
}

void	sort_five_a(t_stack *stack)
{
	while (current_size(&stack->a) > 3)
	{
		if (stack->a.array[0] == 1 || stack->a.array[1])
			push_b(stack);
		else
			rotate_a(stack);
	}
	if (stack->a.array[0] < stack->a.array[1])
		swap_b(stack);
	sort_three_a(stack);
	push_a(stack);
	push_a(stack);
}
