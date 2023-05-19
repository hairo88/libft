/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:38:58 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 09:24:40 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_con_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_con_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	while (i < dstsize - 1 - dst_len)
	{
		if (src[i] == 0)
			break ;
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
