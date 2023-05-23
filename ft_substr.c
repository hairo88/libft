/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:17 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/23 12:44:58 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!len || ft_strlen(s) < start)
	{
		ans = ft_strdup("");
		return (ans);
	}
	ans = ft_calloc(sizeof(char), (len + 1));
	if (ans == NULL)
		return (NULL);
	ans[0] = 0;
	while (i < len && s[start + i])
	{
		ans[i] = s[start + i];
		i++;
	}
	return (ans);
}
