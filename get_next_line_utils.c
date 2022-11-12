/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:43:20 by ggiannit          #+#    #+#             */
/*   Updated: 2022/11/12 14:39:08 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cmem;
	size_t	k;
	size_t	tot_size;

	k = 0;
	if (!nmemb || !size)
		return (NULL);
	tot_size = nmemb * size;
	cmem = (char *) malloc(tot_size);
	if (!cmem)
		return (NULL);
	while (k < tot_size)
		cmem[k++] = '\0';
	return (cmem);
}

size_t	ft_strlen(char *str)
{
	size_t	k;

	k = 0;
	if (!str || !(*str))
		return (0);
	while (str[k] != 0)
		k++;
	return (k);
}

ssize_t	ft_get_line_size(char *buff_read)
{
	ssize_t	k;

	k = 0;
	if (!buff_read)
		return (0);
	while (buff_read[k] != '\0')
	{
		if (buff_read[k] == '\n')
			return (++k);
		k++;
	}
	return (k);
}

int	ft_search_bsn(char *buff_read)
{
	if (!buff_read)
		return (0);
	while (*buff_read)
	{
		if (*buff_read == '\n')
			return (1);
		buff_read++;
	}
	return (0);
}

void	*ft_free_null(char **read)
{
	if (!*read)
		return (NULL);
	free(*read);
	*read = NULL;
	return (NULL);
}
