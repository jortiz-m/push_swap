/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 08:52:28 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/10 09:52:00 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignbr(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n > 9)
		count += ft_putunsignbr(n / 10);
	count += ft_putchar('0' + n % 10);
	return (count);
}
