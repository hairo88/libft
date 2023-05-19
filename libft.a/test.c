/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:31:16 by kotainou          #+#    #+#             */
/*   Updated: 2023/05/18 20:27:20 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_charset(char str, char *charset)
{
    int i = 0;
    while (charset[i])
    {
        if (charset[i] == str)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strndup(char *str, int n)
{
    char *ans;
    int i = 0;
    ans = malloc(sizeof(char) * (n + 1));
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

int	ft_count_array(char *str, char *charset)
{
	int	ans;
	int	i;

	ans = 0;
	i = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			ans++;
		i++;
	}
	return (ans);
}

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int arr_num = 0;
    char **ans;
    int count;
    int j = 0;
    char *tmp;

	ans = NULL;
	arr_num = ft_count_array(str, charset);
	ans = (char **)malloc(sizeof(char *) * (arr_num + 1));
	if (ans == NULL)
		return (NULL);
    while (str[i])
    {
        if (is_charset(str[i], charset))
            i++;
        else
        {
            tmp = &str[i];
            count = 0;
            while (str[i] && !(is_charset(str[i], charset)))
            {
                count++;
                i++;
            }
            ans[j] = ft_strndup(tmp, count);
            j++;
        }
    }
    ans[j] = NULL;  // 二次配列の終端を示すためにNULLを追加
    return (ans);
}

int main()
{
    char *str = "This is/a#test!@string";
    char *charset = " /!#@";
    char **result = ft_split(str, charset);

    int i = 0;
    while (result[i] != NULL)
    {
        printf("%s\n", result[i]);
        free(result[i]); // メモリ解放
        i++;
    }
    free(result); // 二次配列のメモリ解放

    return 0;
}

