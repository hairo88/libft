/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:41:11 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 18:47:56 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	ans;

	ans = 0;
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		ans = 1;
	return (ans);
}
