/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:27:26 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/09/23 10:17:02 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

/**
 * @brief 
 * 
 * @param str 
 * @param ... 
 * @return int 
 */
int		ft_printf(const char *str, ...);
/**
 * @brief 
 * 
 */
int		ft_putnbr(int n);
/**
 * @brief 
 * 
 */
int		ft_puthex(unsigned long long lst, char c);
/**
 * @brief 
 * 
 */
int		ft_putunsignbr(unsigned int n);
/**
 * @brief 
 * 
 */
int		ft_putchar(char c);
/**
 * @brief 
 * 
 */
int		ft_putstr(char *lst);
/**
 * @brief 
 * 
 */
int		ft_hexapointer(uintptr_t ptr);

#endif