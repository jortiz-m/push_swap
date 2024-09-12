/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:31:33 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 13:42:11 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	start_data(&stack, argc, argv, true);
	sort(&stack);
	show_moves(stacks.op_list);
	exit (EXIT_SUCCESS);
}
