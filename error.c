/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:23:11 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/23 10:03:28 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *stacks)
{
	free_stacks(stacks);
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i])
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
}

void	free_and_exit(t_stack *stacks)
{
	free_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void	free_stacks(t_stack *stacks)
{
	if (stacks->a.array)
		free(stacks->a.array);
	if (stacks->b.array)
		free(stacks->b.array);
	if (stacks->op_list)
		ft_lstclear(&stacks->op_list, NULL);
}
