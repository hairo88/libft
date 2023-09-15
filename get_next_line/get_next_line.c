/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotainou <kotainou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:32:41 by kotainou          #+#    #+#             */
/*   Updated: 2023/06/07 13:39:05 by kotainou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*now_text[OPEN_MAX];
	char		*line_text;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	status = 0;
	now_text[fd] = ft_read_buffer(fd, now_text[fd], &status);
	if (status == 1)
	{
		free(now_text[fd]);
		return (NULL);
	}
	if (now_text[fd] == NULL)
		return (NULL);
	line_text = ft_newline_text(now_text[fd]);
	now_text[fd] = ft_next_text(now_text[fd]);
	return (line_text);
}

char	*ft_read_buffer(int fd, char *now_text, int *status)
{
	char	*buffer;
	int		read_num;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_num = 1;
	while (!ft_strchr(now_text, '\n') && read_num != 0)
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num == -1)
		{
			free(buffer);
			*status = 1;
			return (NULL);
		}
		buffer[read_num] = 0;
		now_text = ft_strjoin_free(now_text, buffer);
	}
	free(buffer);
	return (now_text);
}

char	*ft_newline_text(char *now_text)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (!now_text[i])
		return (NULL);
	while (now_text[i] && now_text[i] != '\n')
		i++;
	ans = ft_calloc(sizeof(char), (i + 2));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (now_text[i] && now_text[i] != '\n')
	{
		ans[i] = now_text[i];
		i++;
	}
	if (now_text[i] && now_text[i] == '\n')
		ans[i] = '\n';
	return (ans);
}

char	*ft_next_text(char *now_text)
{
	size_t	i;
	size_t	j;
	char	*ans;

	i = 0;
	while (now_text[i] && now_text[i] != '\n')
		i++;
	if (!now_text[i])
	{
		free(now_text);
		return (NULL);
	}
	ans = ft_calloc(sizeof(char), (ft_strlen(now_text) - i + 1));
	if (ans == NULL)
	{
		free(now_text);
		return (NULL);
	}
	i++;
	j = 0;
	while (now_text[i])
		ans[j++] = now_text[i++];
	free(now_text);
	return (ans);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	// char	*ans4;
// 	size_t	i;
// 	i = 0;
// 	fd1 = open("file1", O_RDONLY);
// 	fd2 = open("file2", O_RDONLY);
// 	// printf("test 2\n");
// 	// ans4 = get_next_line(fd);
// 	printf("fd1 -----------------\n");
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	//printf("%s", get_next_line(fd1));
// 	printf("\nfd2 -----------------\n");
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	//printf("%s", get_next_line(fd2));
// 	// printf("4=%s", ans4);
// }
