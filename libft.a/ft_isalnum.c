/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:47:53 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 15:07:43 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	ans;

	ans = 0;
	if ('0' <= c && c <= '9')
		ans = 1;
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		ans = 1;
	return (ans);
}

// #include <stdio.h>
// int main()
// {
// 	printf("current = %d, ft_usalnum = %d\n", isalnum('a'), ft_isalnum('a'));
// }