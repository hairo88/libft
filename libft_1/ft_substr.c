/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:17 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 18:58:15 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		ans = "";
		return (ans);
	}
	ans = malloc(sizeof(char) * (s_len + 1));
	if (ans == NULL)
		return (NULL);
	ans[0] = 0;
	while (i < len && s[start + i])
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char 			*s = "libft-test-tokyo";
// 	unsigned int    start = 0;
// 	size_t			len = 100;

// 	//printf("ft_substr = %s\n current = %s\n", ft_substr(s, 20, 100), "");
// 	if (strcmp(ft_substr(s, start, len), s) == 0)
// 		printf("OK\n");
// 	else
// 		printf("NOOO\n");
// 	printf("ft_substr = %s\n", ft_substr(s, 20, 100));
// 	printf("   substr = %s\n", s);
// 	//printf("%zu\n", ft_strlen(s));
// }
