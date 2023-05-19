/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:00:17 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/16 18:59:59 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	int		i;

	i = 0;
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	while (i < len)
	{
		ans[i] = s[len + i];
		i++;
	}
	return (ans);
}

int main()
{
	printf("%s\n", ft_substr("abcdef", 1, 3));
	printf("%s\n", ft_substr("abcdef", 0, 3));
	printf("%s\n", ft_substr("abcdef", 1, 1));
}
