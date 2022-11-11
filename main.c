/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:11:13 by ggiannit          #+#    #+#             */
/*   Updated: 2022/11/11 15:24:43 by ggiannit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*nline;
	int	i;

	i = 0;
	fd = open("testfile", O_RDONLY);
	nline = get_next_line(fd);
	while (i++ < 9)
	{
		printf("%s", nline);
		free(nline);
		nline = get_next_line(fd);
	}
	free(nline);
	close(fd);
}
