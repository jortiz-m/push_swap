/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:47:32 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/23 10:06:20 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	next_down(t_pile *pile, int index)
{
	if (current_size(pile) == 0)
		return (index);
	if (index == pile->size - 1)
		return (0);
	else
		return (index + 1);
}

int	next_up(t_pile *pile, int index)
{
	if (current_size(pile) == 0)
		return (index);
	if (index == 0)
		return (pile->size - 1);
	else
		return (index - 1);
}

bool	is_full(t_pile *pile)
{
	return (pile->size == current_size(pile));
}

int	current_size(t_pile *pile)
{
	if (pile->top == pile->bottom && !pile->array[pile->top])
		return (0);
	if (pile->top > pile->bottom)
		return ((pile->size - pile->top) + (pile->bottom + 1));
	else
		return (pile->bottom - pile->top + 1);
}
