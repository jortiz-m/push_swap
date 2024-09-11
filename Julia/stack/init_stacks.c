/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:35:54 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/11 10:35:56 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_stacks(t_stack *stacks, int ac, char **av)
{
	char	**split_av;

	split_av = av;
	if (ac == 2)
	{
		split_av = process_av(&ac, av);
		if (!split_av)
			exit(EXIT_FAILURE);
	}
	else
		++split_av;
	--ac;
	init_pile(stacks, &stacks->a, ac);
	init_pile(stacks, &stacks->b, ac);
	fill_pile(stacks, &stacks->a, ac, split_av);
	stacks->op_list = NULL;
}

void	init_pile(t_stack *stacks, t_pile *pile, int ac)
{
	pile->array = malloc(ac * sizeof(int));
	if (!pile->array)
		error(stacks);
	pile->top = 0;
	pile->bottom = 0;
	pile->size = ac;
	ft_memset(&pile->array, 0, ac);
}

char	**process_av(int *ac, char **av)
{
	int		i;
	char	**splitted_av;

	if (av == NULL)
		return (NULL);
	i = 0;
	splitted_av = ft_split(av[1], ' ');
	while (splitted_av[i])
		i++;
	*ac = i + 1;
	return (splitted_av);
}
