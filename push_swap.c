/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:24:59 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/08/05 13:43:41 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*start;

	start = ft_arguments(argc, argv);
	if (!start || ft_oneargument(start))
	{
		ft_free(&start);
		ft_error();
	}
	if (!ft_isorder(start))
		ft_sort(&start);
	ft_free(&start);
	return (0);
}
