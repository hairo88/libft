/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:05:42 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 12:34:19 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_con_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ans;
	int		size;
	int		index;

	index = 0;
	size = ft_con_strlen(src);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (ans == NULL)
		return (NULL);
	while (src[index])
	{
		ans[index] = src[index];
		index++;
	}
	ans[index] = 0;
	return (ans);
}
