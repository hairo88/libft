/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:29 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/23 13:10:38 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	size_t	str;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[str]) && str < end)
		str++;
	while (ft_strrchr(set, s1[end - 1]) && str < end)
		end--;
	ans = ft_calloc(sizeof(char), end - str + 1);
	if (ans == NULL)
		return (NULL);
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

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *s = ft_strtrim("   xxxtripouille", " x");
// 	if (strcmp(s, "tripouille") == 0)
// 	{
// 		printf("OK :%s\n", s);
// 	}
// 	else
// 	{
// 		printf("KO :%s\n", s);
// 	}
// }
