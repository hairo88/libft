/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:15:12 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 09:11:03 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (dest[sum])
		sum++;
	while (src[i])
	{
		dest[sum + i] = src[i];
		i++;
	}
	dest[sum + i] = 0;
	return (dest);
}

int	ft_total_str(char	*str1, char *str2)
{
	int		sum;

	sum = 0;
	sum += ft_strlen(str1) + ft_strlen(str2);
	sum++;
	return (sum);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ans;
	int		i;

	i = 0;
	ans = malloc(sizeof(char) * (ft_total_str(str1, str2) + 1));
	if (!ans)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		ans[i] = str1[i];
		i++;
	}
	ft_strcat(ans, str2);
	return (ans);
}

// int	main(void)
// {
// 	/* 1 */ printf("%s %s\n", ft_strjoin("hello", "world"), "helloworld");
// 	/* 2 */ printf("%s %s\n", ft_strjoin("", "world"), "world");
// 	/* 3 */ printf("%s %s\n", ft_strjoin("hello", ""), "hello");
// 	/* 4 */ printf("%s %s\n", ft_strjoin("", ""), "");
// }
