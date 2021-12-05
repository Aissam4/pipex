/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:02:29 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 05:05:34 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

char    *get_next_line(int fd)
{
    int     byte;
    int     i;
    char    line[8000000] = {0};
    char    buffer[1];

    i = 0;
    while ((byte = read(fd, buffer, 1)) > 0)
    {
        line[i++] = buffer[0];
        if (buffer[0] == '\n')
            return (ft_strdup(line));
    }
    if (!line[0])
        return (NULL);
    return (ft_strdup(line));
}