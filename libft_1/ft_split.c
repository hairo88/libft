/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:11 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/22 20:27:53 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//大きい箱を作る場所
static	size_t	ft_count_words(char	const *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	ans;
	size_t	flag;

	i = 0;
	ans = 0;
	start = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != c && i > start && !flag)
		{
			ans++;
			start = i + 1;
			flag = 1;
		}
		if (flag && str[i] == c)
			flag = 0;
		i++;
	}
	return (ans);
}

//小さい箱を作る
static	char	*ft_strdup_split(char *str, char c)
{
	size_t	str_len;
	size_t	i;
	char	*ans;

	i = 0;
	str_len = 0;
	while (str[str_len] != c)
		str_len++;
	ans = ft_calloc(sizeof(char), (str_len + 1));
	if (ans == NULL)
		return (NULL);
	while (i < str_len)
	{
		ans[i] = str[i];
		i++;
	}
	return (ans);
}

//チェックするところ
static	void	ft_cheak(char **ans, int j)
{
	size_t	i;

	i = 0;
	if (ans[j] == NULL)
	{
		while ((int)i < j)
		{
			free(ans[i]);
			i++;
		}
		free(ans);
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count_words;
	char	**ans;

	i = 0;
	j = 0;
	count_words = ft_count_words(s, c);
	ans = ft_calloc(sizeof(char *), (count_words + 1));
	if (ans == NULL)
		return (NULL);
	while (s[i] && j < count_words)
	{
		if ((s[i] != c && s[i + 1] == c) || (i == 0 && s[i] != c))
		{
			printf("%d\n, i");
			if (i == 0)
				ans[j] = ft_strdup_split((char *)&s[i], c);
			else
				ans[j] = ft_strdup_split((char *)&s[i], c);
			ft_cheak(ans, j);
			j++;
		}
		i++;
	}
	return (ans);
}

#include <stdio.h>

int	main(void)
{
	char	*test_text = ",,,hello,,,world,,,42,,,tokyo,,,,";
	char	charset = ' ';
	char	**ans;
	size_t	i;
	//size_t	j;

	i = 0;
	ans = ft_split(test_text, charset);
	while (ans[i])
	{
		//printf("[%d]\n", i);
		printf("%s\n", ans[i]);
		i++;
	}
	free(ans);
	return (0);
}
