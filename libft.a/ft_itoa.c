/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:34:06 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 14:45:31 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_count_keta(int n)
{
	int	ans;

	ans = 0;
	if (n < 0)
	{
		ans++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		ans++;
	}
	return (ans);
}

char	*ft_array_number(char *ans, int n, int str_len)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while (i < str_len - sign)
	{
		ans[str_len - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (sign)
		ans[0] = '-';
	ans[i + sign] = 0;
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		i;
	int		str_len;
	int		sign;

	i = 0;
	str_len = ft_count_keta(n);
	ans = malloc(sizeof(char) * (str_len + 1));
	if (ans == NULL)
		return (NULL);
	ans = ft_array_number(ans, n, str_len);
	return (ans);
}
