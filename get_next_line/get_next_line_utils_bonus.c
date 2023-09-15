/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bouns.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:42:05 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/07 13:45:09 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	char	*ans;

	ans = ft_strjoin(str1, str2);
	free(str1);
	return (ans);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	char	*ans;

	if (!str2)
		return (NULL);
	if (!str1)
		ans = (char *)ft_calloc(ft_strlen(str2) + 1, sizeof(char));
	else
		ans = ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), sizeof(char));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (str1 && *str1)
			ans[i++] = *str1++;
	while (*str2)
		ans[i++] = *str2++;
	return (ans);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	else if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ans = (void *)malloc(count * size);
	if (ans == NULL)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)ans)[i] = 0;
		i++;
	}
	return (ans);
}
