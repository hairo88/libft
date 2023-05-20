/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:11 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/20 12:33:46 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//大きい箱の必要数
static	int	ft_count_words(char	const *str, char c)
{
	size_t	i;
	int		start;
	int		ans;

	i = 0;
	ans = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == c && i > start)
		{
			ans++;
			start = i + 1;
		}
		i++;
	}
	return (ans);
}

//小さい箱の必要数とその文字列
static	char	*ft_strdup_split(char *str, char c)
{
	size_t	str_len;
	size_t	i;
	char	*ans;

	i = 0;
	str_len = 0;
	while (str[str_len] != c)
		str_len++;
	ans = malloc(sizeof(char) * (str_len + 1));
	if (ans == NULL)
		return (NULL);
	while (i < str_len)
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}

//箱の中身をチャック
static	void	ft_cheak(char **ans, int n)
{
	size_t	i;

	i = 0;
	while (ans[i])
	{
		if (!ans[i])
			return ;
		i++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		count_words;
	char	**ans;

	i = 0;
	j = 0;
	count_words = ft_count_words(s, c);
	ans = malloc(sizeof(char *) * (count_words + 1));
	while (s[i])
	{
		if ((char)s[i] == c || i == 0)
		{
			if (i == 0)
				ans[j] = ft_strdup_split((char *)&s[i], c);
			else
				ans[j] = ft_strdup_split((char *)&s[i + 1], c);
			j++;
		}
		i++;
	}
	ans[i] = 0;
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test_text = "this is a pen";
// 	char	charset = ' ';
// 	char	**ans;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	ans = ft_split(test_text, charset);
// 	while (ans[i])
// 	{
// 		printf("%s\n", ans[i]);
// 		i++;
// 	}
// 	return (0);
// }
