/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:22:41 by skawanis          #+#    #+#             */
/*   Updated: 2023/05/02 11:00:29 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 4

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*memo;
	ssize_t		read_return;

	if (memo != NULL && ft_strchr(memo, '\n'))
	{
		line = ft_strcdup(memo, '\n');
		memo = ft_strdup(ft_strchr(memo, '\n') + 1);
	}
	else
	{
		buf = malloc(BUFFER_SIZE + 1);
		while (memo == NULL || !ft_strchr(memo, '\n'))
		{
			read_return = read(fd, &buf, BUFFER_SIZE);
			memo = ft_strjoin(memo, buf);
			if (memo != NULL && ft_strchr(memo, '\n'))
			{
				line = ft_strcdup(memo, '\n');
				return (line);
			}
			if (read_return < BUFFER_SIZE)
			{
				ft_memcpy(line, memo, ft_strlen_s(memo));
				return (line);
			}
		}
		line = ft_strcdup(memo, '\n');
		memo = ft_strdup(ft_strchr(memo, '\n') + 1);
	}
	return (line);
}
