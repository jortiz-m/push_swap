/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:31:33 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/23 10:05:30 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;
	char	**split_av;
	bool	split_flag;

	split_flag = false;
	split_av = init_stacks(&stacks, ac, av, &split_flag);
	sort(&stacks, split_av, &split_flag);
	if (split_flag)
		free_split(split_av);
	free_and_exit(&stacks);
}
