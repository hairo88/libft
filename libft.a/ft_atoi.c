/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:14:30 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 14:49:40 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	ans;
	size_t		i;
	int			sign;
	int			count;

	i = 0;
	ans = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		count++;
	}
	if (count > 1)
		return (0);
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return (sign * ans);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	char *test = "18446744073709551614";
// 	printf("atoi = %d\n", atoi(test));
// 	printf("ft_atoi = %d\n", ft_atoi(test));
// }
