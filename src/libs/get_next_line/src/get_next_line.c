/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:30:35 by aeddaoud          #+#    #+#             */
/*   Updated: 2021/12/11 12:48:44 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_chunk(int fd)
{
	int		i;
	char	*str;
	char	*buffer;

	str = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		str = ft_strjoin_gnl(str, buffer, 1, 0);
		if (i == 0 || ft_strchr_gnl(buffer, '\n'))
		{
			free(buffer);
			return (str);
		}
	}
	return (NULL);
}

static char	*save_rest(char *str)
{
	size_t	i;
	char	*buff;

	str = ft_strchr_gnl(str, '\n');
	i = ft_strlen_gnl(str);
	if (*(str + 1) == '\0')
		return (NULL);
	buff = (char *)malloc(i * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (str[i + 1])
	{
		buff[i] = str[i + 1];
		i++;
	}
	buff[i] = 0;
	return (buff);
}

static char	*get_line(char *str)
{
	size_t	i;
	char	*buff;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	buff = (char *)malloc((i + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while (str[i])
	{
		buff[i] = str[i];
		if (str[i] == '\n')
			break ;
		i++;
	}
	buff[i + 1] = 0;
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*chunk;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunk = get_chunk(fd);
	str = ft_strjoin_gnl(buff, chunk, 1, 1);
	if (str && *str == '\0')
	{
		free(str);
		return (NULL);
	}
	buff = NULL;
	if (ft_strchr_gnl(str, '\n'))
	{
		buff = save_rest(str);
		return (get_line(str));
	}
	return (str);
}
