/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:42:14 by ggiannit          #+#    #+#             */
/*   Updated: 2022/11/11 17:57:48 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
//# define BUFFER_SIZE 4009
#  define BUFFER_SIZE 12
# endif

char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
ssize_t	ft_get_line_size(char *buff_read);
int		ft_search_bsn(char *buff_read);
void	*ft_free_null(char **read);

#endif
