/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:49:51 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/10 18:02:49 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_dec_to_hex_main(unsigned int nbr, char format)
{
	size_t	count;

	count = 0;
	if (format == 'x')
		ft_put_dec_to_hex_small(nbr);
	else if (format == 'X')
		ft_put_dec_to_hex_big(nbr);
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

void	ft_put_dec_to_hex_small(unsigned int nbr)
{
	size_t		out_put;
	const char	*pointer_arry = "0123456789abcdef";

	if (16 <= nbr)
		ft_put_dec_to_hex_small(nbr / 16);
	out_put = nbr % 16;
	write(1, &pointer_arry[out_put], 1);
}

void	ft_put_dec_to_hex_big(unsigned int nbr)
{
	size_t		out_put;
	const char	*pointer_arry = "0123456789ABCDEF";

	if (16 <= nbr)
		ft_put_dec_to_hex_big(nbr / 16);
	out_put = nbr % 16;
	write(1, &pointer_arry[out_put], 1);
}
