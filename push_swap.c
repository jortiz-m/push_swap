/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:24:59 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/08/06 11:20:53 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_arguments(argc, argv);
	if (!a || ft_repeat(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_isorder(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
