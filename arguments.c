/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:26:42 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/08/05 13:44:51 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_myatoi(const char *str)
{
	int	i;
	int	number;
	int	neg;

	i = 0;
	number = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if ((number * i) > INT_MAX || (number * i) < INT_MIN)
		ft_error();
	return (number * neg);
}

t_stack	*ft_oneargument(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_myatoi(tmp[i]);
		ft_add_back(&a, ft_stack_new(j)); //funciones sin hacer
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	*ft_arguments(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_oneargument(argv);
	else
	{
		while (i < argc)
		{
			j = ft_myatoi(argv[i]);
			ft_add_back(&a, ft_stack_new(j)); //funciones sin hacer
			i++;
		}
	}
	return (a);
}
