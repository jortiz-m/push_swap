/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:17:28 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/11 10:24:43 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	chunk_sort(t_stack *stack) /* Init chunk creo que tiene mas sentido para el nombre */
{
	t_chunk chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = stack->a.size;
	rec_chunk_sort(stack, &chunk_all)
}

void	rec_chunk_sort(t_stack *stack, t_chunk *to_sort) /* to_sort puede ser chunk_all para conservar legibilidad*/
{
	t_split_dest	dest;

	chunk_to_the_top(stack, to_sort); /* utiliza el stack para comprobar tamaño de la pila || La primera vez que se llama no hace nada ya que es TOP_A*/
	if (to_sort->size < 3)
	{
		else if (to_sort->size == 2)
			sort_two(stack, to_sort);
		else if (to_sort->size == 1)
			sort_one(stack, to_sort);
		return ;
	}
	chunk_split(stack, to_sort, &dest)
	rec_chunk_sort(stack, &dest.max);
	rec_chunk_sort(stack, &dest.mid);
	rec_chunk_sort(stack, &dest.min);
}

void	sort_two(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
	{
		move_from_to(stack, to_sort->loc, TOP_A);
		move_from_to(stack, to_sort->loc, TOP_A);
	}
	if (stack->a.array[0] > stack->a.array[1])
		swap_a(stack);
	to_sort->size = to_sort->size - 2;
}

void	sort_one(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
		move_from_to(stack, to_sort->loc, TOP_A);
	to_sort->size = to_sort->size - 1;
}
