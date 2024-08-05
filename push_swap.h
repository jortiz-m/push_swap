/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:41:00 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/08/05 13:03:46 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

#include "./libft/libft.h"
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	int			number;
	int			position;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#endif