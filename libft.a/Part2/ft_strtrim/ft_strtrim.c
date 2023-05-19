/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:56:29 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/18 17:06:26 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;
	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s == unsigned char(c))
			break ;
		s++;
	}
	return (s);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		ans_len;
	int		str;
	int		end;

	ans_len = ft_strlen(s1);
	str = 0;
	end = ans_len;
	ans = malloc(sizeof(char) * (ans_len + 1));
	while (ft_strchr(set, s1[str]) && str < end)
		str++;
	while (ft_strchr(set, s1[str]) && str < end)
		end--;

