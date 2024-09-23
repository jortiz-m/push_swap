/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:19:46 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/13 09:34:26 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long lst, char c)
{
	unsigned long long	count;

	count = 0;
	if (lst >= 16)
		count += ft_puthex(lst / 16, c);
	if (c == 'x')
		ft_putchar("0123456789abcdef" [lst % 16]);
	if (c == 'X')
		ft_putchar("0123456789ABCDEF" [lst % 16]);
	count ++;
	return (count);
}
