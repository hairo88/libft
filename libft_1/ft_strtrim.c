/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:29 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 18:57:48 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (s[n] == c)
		return ((char *)&s[n]);
	while (n > 0)
	{
		n--;
		if (s[n] == (char)c)
			return ((char *)&s[n]);
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	size_t	ans_len;
	size_t	str;
	size_t	end;
	size_t	i;

	ans_len = ft_strlen(s1);
	str = 0;
	end = ans_len;
	ans = malloc(sizeof(char) * (ans_len + 1));
	if (ans == NULL)
		return (NULL);
	while (ft_strchr(set, s1[str]) && str < end)
		str++;
	while (ft_strrchr(set, s1[end - 1]) && str < end)
		end--;
	i = 0;
	while (str < end)
	{
		ans[i] = s1[str];
		i++;
		str++;
	}
	ans[i] = 0;
	return (ans);
}
