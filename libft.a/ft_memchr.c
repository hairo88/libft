/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:14:18 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 13:35:59 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (c == ((unsigned char *)s)[i])
			return ((void *)(char *)&s[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//         char str[] = "abcdef\0ghij";    /* 途中に空文字のある文字列 */
//         char *p;
// 		char *sed_p;

//         p = memchr(str, 'h', 12);
// 		sed_p = ft_memchr(str, 'h', 12);
//         printf("検索文字は文字列の%ld番目\n",p - str);
//         printf("検索文字は文字列の%ld番目\n",sed_p - str);

//         return 0;
// }
