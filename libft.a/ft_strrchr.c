/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:07:26 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 09:10:39 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (s[n] == c)
		return ((char *)&s[n]);
	while (n > 0)
	{
		n--;
		if (s[n] == c)
			return ((char *)&s[n]);
	}
	return (NULL);
}
