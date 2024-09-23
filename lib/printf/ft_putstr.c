/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:22:55 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/10 13:10:32 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *lst)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (lst == NULL)
		lst = "(null)";
	while (lst[i] != '\0')
	{
		count += ft_putchar(lst[i]);
		i++;
	}
	return (count);
}
