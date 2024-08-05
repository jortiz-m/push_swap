/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:45:54 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/08/05 13:48:11 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **str)
{
	char	*lst;

	if (!str)
		return ;
	while (*str)
	{
		lst = *str;
		str++;
		free(lst);
	}
	*str = NULL;
}
