/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:43:20 by wlin              #+#    #+#             */
/*   Updated: 2017/07/28 13:08:37 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read(char **fd_buf, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*sptr;
	int		ret;

	if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	buffer[ret] = '\0';
	sptr = *fd_buf;
	*fd_buf = ft_strjoin(*fd_buf, buffer);
	if (*sptr != 0)
		free(sptr);
	return (ret);
}

static int		ft_check_nl(char **buffer, char **line, char *sptr)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if (*sptr == '\n')
		ret = 1;
	*sptr = '\0';
	*line = ft_strdup(*buffer);
	if (ret == 0 && ft_strlen(*buffer) != 0)
	{
		ft_strdel(buffer);
		return (1);
	}
	else if (ret == 0 && !(ft_strlen(*buffer)))
	{
		ft_strdel(buffer);
		return (0);
	}
	tmp = *buffer;
	*buffer = ft_strdup(sptr + 1);
	if (*(*buffer) == 0)
		ft_strdel(buffer);
	free(tmp);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char		*fd_arr[1024];
	char			*sptr;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (fd_arr[fd % 1024] == 0)
		fd_arr[fd % 1024] = "";
	ret = BUFF_SIZE;
	while (line)
	{
		sptr = fd_arr[fd % 1024];
		while (*sptr || ret < BUFF_SIZE)
		{
			if (*sptr == '\n' || *sptr == 0)
				return (ft_check_nl(&fd_arr[fd % 1024], line, sptr));
			++sptr;
		}
		if ((ret = ft_read(&fd_arr[fd % 1024], fd)) == -1)
			return (-1);
	}
	return (0);
}
