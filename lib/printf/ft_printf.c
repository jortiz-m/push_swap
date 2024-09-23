/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:58:40 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/05/16 09:29:21 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list lst, char c )
{
	int	totallen;

	totallen = 0;
	if (c == 'c')
		totallen = ft_putchar((char)va_arg(lst, int));
	else if (c == 's')
		totallen = ft_putstr(va_arg (lst, char *));
	else if (c == 'd' || c == 'i')
		totallen = ft_putnbr(va_arg (lst, int));
	else if (c == 'u')
		totallen = ft_putunsignbr(va_arg (lst, int));
	else if (c == 'X' || c == 'x')
		totallen = ft_puthex(va_arg (lst, unsigned int), c);
	else if (c == 'p')
		totallen = ft_hexapointer(va_arg (lst, uintptr_t));
	else
		return (write (1, "%", 1));
	return (totallen);
}

void	ft_check(va_list lst, const char *str, int *i, int *len)
{
	if (str[*i] == '%')
	{
		(*i)++;
		(*len) += ft_format(lst, str[*i]);
		(*i)++;
	}
	else
	{
		ft_putchar((char)str[*i]);
		(*i)++;
		(*len)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(lst, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i] != '\0')
		ft_check(lst, str, &i, &len);
	va_end (lst);
	return (len);
}
