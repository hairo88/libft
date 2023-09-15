/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:27:10 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/10 17:54:39 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_main(int n, int fd)
{
	ft_putnbr_fd(n, fd);
	return (ft_putnbr_count(n));
}

void	ft_putnbr_fd(int n, int fd)
{
	char	out_put;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (10 <= n)
		ft_putnbr_fd(n / 10, fd);
	out_put = n % 10 + '0';
	write(fd, &out_put, 1);
}

size_t	ft_putnbr_count(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

size_t	ft_unsign_putnbr_main(unsigned int n, int fd)
{
	ft_unsign_putnbr_fd(n, fd);
	return (ft_putnbr_count_unsign(n));
}

void	ft_unsign_putnbr_fd(unsigned int n, int fd)
{
	char	out_put;

	if (10 <= n)
		ft_putnbr_fd(n / 10, fd);
	out_put = n % 10 + '0';
	write(fd, &out_put, 1);
}

// int main()
// {
// 	printf("%zu\n", ft_putnbr_count(-9223378));
// }