/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:54:34 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 14:44:12 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_con_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*ans;

	i = 0;
	s_len = ft_con_strlen(s);
	if (s == NULL || f == NULL)
		return (NULL);
	ans = malloc(sizeof(char) * (s_len + 1));
	if (ans == NULL)
		return (NULL);
	while (s[i])
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = 0;
	return (ans);
}
