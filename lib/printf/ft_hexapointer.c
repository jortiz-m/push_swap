/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexapointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:02:42 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/14 10:43:12 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexapointer(uintptr_t ptr)
{
	int		count;

	count = 0;
	count += (write(1, "0", 1));
	count += (write(1, "x", 1));
	count += ft_puthex(ptr, 'x');
	return (count);
}
