/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:36:03 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/12 10:33:31 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	valid_av(char *av)
{
	int			sign;
	long long	num;

	sign = 1;
	if (*av == '\0')
		return (false);
	if (*av == '-' || av == '+')
	{
		if (*av == '-')
			sign = -1;
		av++;
		if (*av == '\0')
			return (false);
	}
	num = 0;
	while (*av)
	{
		if (!ft_isdigit(av))
			return (false);
		num = num * 10 + (*av - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num < INT_MIN))
			return (false);
		*av++;
	}
	return (true);
}

void	check_doubles(t_stack *stacks, int *nums, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				error(stacks);
			}
			j++;
		}
		i++;
	}
}

void	nums_ranked(int *nums, int *pile, int ac)
{
	int	i;
	int	j;
	int	count_bigger;

	i = 0;
	while (i < ac)
	{
		j = 0;
		count_bigger = 0;
		while (j < ac)
		{
			if (nums[i] >= nums[j])
				count_bigger++;
			j++;
		}
		pile[i] = count_bigger;
		i++;
	}
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
