/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:38:10 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/13 14:01:20 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer_next(unsigned long pointer, size_t *count)
{
	size_t		out_put;
	const char	*pointer_arry = "0123456789abcdef";

	if (16 <= (unsigned long)pointer)
		ft_put_pointer_next((unsigned long )pointer / 16, count);
	out_put = (unsigned long )pointer % 16;
	if (pointer != 0)
		*count += write(1, &pointer_arry[out_put], 1);
}

size_t	ft_putpoint(void	*pointer)
{
	unsigned long	next_pointer;
	size_t			count;

	count = 0;
	next_pointer = (unsigned long)pointer;
	write(1, "0x", 2);
	count += 2;
	if (pointer == 0)
		count += write(1, "0", 1);
	ft_put_pointer_next(next_pointer, &count);
	return (count);
}
