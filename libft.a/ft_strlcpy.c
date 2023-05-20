/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:35:20 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 14:42:55 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char src[] = "Hello, World!";
//     char dest[20];

//     size_t len = strlcpy(dest, src, sizeof(dest));
//     printf("strlcpy: %s (length: %zu)\n", dest, len);

//     len = ft_strlcpy(dest, src, sizeof(dest));
//     printf("ft_strlcpy: %s (length: %zu)\n", dest, len);

//     return 0;
// }
