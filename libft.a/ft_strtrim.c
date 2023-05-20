/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:29 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 13:57:58 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int	ft_con_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		ans_len;
	int		str;
	int		end;
	size_t	i;

	ans_len = ft_con_strlen(s1);
	str = 0;
	end = ans_len;
	ans = malloc(sizeof(char) * (ans_len + 1));
	if (ans == NULL)
		return (NULL);
	while (ft_strchr(set, s1[str]) && str < end)
		str++;
	while (ft_strchr(set, s1[str]) && str < end)
		end--;
	i = 0;
	while (str + i < end)
	{
		ans[i] = s1[str];
		i++;
	}
	return (ans);
}


int main()
{
	
}