/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:28:27 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 13:35:10 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	i;

	i = 0;
	ans = (void *)malloc(count * size);
	if (ans == NULL)
		return (NULL);
	ft_bzero(ans, 0);
	return (ans);
}
