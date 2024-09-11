/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:36:03 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/11 10:36:06 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

vvoid	fill_pile(t_stack *stacks, t_pile *pile, int ac, char **av)
{
	int	*nums;
	int	i;

	nums = malloc(ac * sizeof(int));
	if (!nums)
		error(stacks);
	i = 0;
	while (av[i])
	{
		if (!valid_av(av[i]))
			error(stacks);
		nums[i] = ft_atoi(av[i]);
		i++;
	}
	check_doubles(stacks, nums, ac);
	nums_ranked(nums, pile->array, ac);
	pile->bottom = ac - 1;
	free(nums);
}

bool	valid_av(char av[])
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
