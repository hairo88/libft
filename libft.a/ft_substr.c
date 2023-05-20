/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:17 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 13:39:18 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	int		i;

	i = 0;
	ans = malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (NULL);
	while (i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	return (ans);
}

// int main()
// {
// 	printf("%s\n", ft_substr("abcdef", 1, 3));
// 	printf("%s\n", ft_substr("abcdef", 0, 3));
// 	printf("%s\n", ft_substr("abcdef", 1, 1));
// }
