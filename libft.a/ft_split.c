/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:46:11 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/19 13:37:53 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//区切り文字かどうかを判断する
int	is_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_array(char *str, char *charset)
{
	int	ans;
	int	i;

	i = 0;
	ans = 0;
	while (str[i])
	{
		if (is_charset(str, charset))
			ans++;
		i++;
	}
	return (ans);
}

//
//char **
//
char	*ft_strndup(char	*str, int n)
{
	char	*ans;
	int		i;

	i = 0;
	ans = malloc((sizeof(char)) * (n + 1));
	if (ans == NULL)
		return (NULL);
	while (i < n && str[i])
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		arr_num;
	char	**ans;
	int		count;
	int		j;
	char	*tmp;

	i = 0;
	arr_num = 0;
	//二次配列の行数を数えている
	while (str[i])
	{
		if (is_charset(str[i], charset))
			i++;
		else
		{
			tmp = &str[i];

	//malloc関数で1回目の動的配列
	ans = malloc((sizeof(char *)) * (arr_num + 1));
	if (ans == NULL)
	{
		printf("error\n");
		return (NULL);
	}
	i = 0;
	//ここで区切り文字が出てくるまでの
	while (str[i])
	{
		if (is_charset(str[i], charset))
			i++;
		else
		{
			tmp = ans[i];
			count = 0;
			while (!(is_charset(str[i], charset)))
			{
				count++;
				i++;
			}
			ans[i] = ft_strndup(tmp, count);
		}
	}
	return (ans);
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *str =  "This is/a#test!@string";
	char *charset = " /!#@";
	ft_split(str, charset);

}
/*
int main()
{
    char *str = "This is/a#test!@string";
    char *charset = " /!#@";
    char **result = ft_split(str, charset);

    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    free(result);

    return 0;
}    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    free(result);

    return 0;
}

*/
