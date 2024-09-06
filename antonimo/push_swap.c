/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:40:24 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/06 12:01:36 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	main(int ac, char **av)
{
	t_stack	stacks;

	init_stacks(&stacks, ac, av, true);
	sort(&stacks);
}
