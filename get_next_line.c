/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:52 by ggiannit          #+#    #+#             */
/*   Updated: 2022/11/12 23:08:24 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_adju_buff(char **buff_read)
{
	char	*new_buff;
	size_t	size_new_buff;
	int		k;
	int		i;

	k = ft_get_line_size(*buff_read);
	if (!k)
		return (NULL);
	size_new_buff = ft_strlen(&((*buff_read)[k]));
	new_buff = (char *) ft_calloc(size_new_buff + 1, sizeof(char));
	if (!new_buff)
		return (NULL);
	i = 0;
	while ((*buff_read)[k] != '\0')
	{
		new_buff[i] = (*buff_read)[k];
		k++;
		i++;
	}
	ft_free_null(buff_read);
	*buff_read = new_buff;
	return (buff_read);
}

char	*ft_substr_read(char **buff_read)
{
	int		i;
	char	*line;
	ssize_t	line_size;

	line_size = ft_get_line_size(*buff_read);
	line = (char *) ft_calloc(line_size + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (line_size--)
	{
		line[i] = (*buff_read)[i];
		i++;
	}
	if (!ft_adju_buff(buff_read))
	{
		ft_free_null(&line);
		return (NULL);
	}
	return (line);
}

char	*ft_strjoin_read(char **old_buff, char **new_buff)
{
	char	*j_str;
	size_t	j_str_size;
	size_t	i;
	size_t	k;

	j_str_size = 0;
	if (*old_buff)
		j_str_size += ft_strlen(*old_buff);
	j_str_size += ft_strlen(*new_buff);
	j_str = ft_calloc(j_str_size + 1, sizeof(char));
	if (!j_str)
		return (ft_free_null(old_buff));
	i = 0;
	k = 0;
	if (*old_buff)
	{
		while ((*old_buff)[k] != '\0')
			j_str[i++] = (*old_buff)[k++];
	}
	k = 0;
	while ((*new_buff)[k] != '\0')
		j_str[i++] = (*new_buff)[k++];
	ft_free_null(old_buff);
	ft_free_null(new_buff);
	return (j_str);
}

int	ft_fill_buff_read(int fd, char **buff_read)
{
	char	*new_read;
	char	*tmp_read;
	int		read_value;

	read_value = 1;
	while (read_value > 0)
	{
		new_read = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_value = read(fd, new_read, BUFFER_SIZE);
		if (read_value)
		{
			tmp_read = ft_strjoin_read(buff_read, &new_read);
			if (!tmp_read)
			{
				ft_free_null(&tmp_read);
				return (0);
			}
			*buff_read = tmp_read;
		}
		if (ft_search_bsn(*buff_read))
			break ;
	}
	ft_free_null(&new_read);
	return (read_value);
}

char	*get_next_line(int fd)
{
	static char	*buff_read;
	char		*line;
	int			flag_going;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!buff_read || !ft_search_bsn(buff_read))
		flag_going = ft_fill_buff_read(fd, &buff_read);
	if (ft_search_bsn(buff_read))
		line = ft_substr_read(&buff_read);
	else if (!flag_going)
	{
		line = ft_substr_read(&buff_read);
		ft_free_null(&buff_read);
		return (line);
	}
	else if (flag_going == -1)
		return (ft_free_null(&buff_read));
	return (line);
}
