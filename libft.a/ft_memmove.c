/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:33:44 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 15:17:42 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest > src)
	{
		n--;
		while (n > 0)
		{
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     //char str1[] = "abcdef";
//     // char str2[] = "abcdef";
//      //char str3[] = "abcdef";
//     char str4[] = "abcdef";
//     //char str11[] = "abcdef";
//     // char str22[] = "abcdef";
//     // char str33[] = "abcdef";
//      char str44[] = "abcdef";

// 	 /*
//     printf("original text : %s\n", str1);
//     ft_memmove(str1 + 2, str1, 4);
//     printf("ft_memmove:\ntest case 1: %s\n", str1);
//     memmove(str11 + 2, str11, 4);
//     printf("memmove:\ntest case 1: %s\n", str11);
// 	*/

// 	 /*
//      ft_memmove(str2, str2 + 2, 4);
//      printf("test case 2: %s\n", str2);
//      memmove(str22, str22 + 2, 4);
//      printf("test case 2ol: %s\n", str22);
// 	*/

// 	 /*
//      ft_memmove(str3 + 2, str3, 4);
//      printf("test case 3: %s\n", str3);

//      memmove(str33 + 2, str33, 4);
//      printf("test case 3ol: %s\n", str33);
// 	*/

//      ft_memmove(str4, str4 + 2, 4);
//      printf("test case 4: %s\n", str4);

//      memmove(str44, str44 + 2, 4);
//      printf("test case 4ol: %s\n", str44);

//     return (0);
// }
