/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:44:31 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 16:20:38 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void     ft_here_doc(char *argv, t_pipex *pipex)
{
    char    *tmp;
    char    *buffer;
    buffer = calloc(1,1);
    
    while (TRUE)
    {
        write(1, "here_doc> ", 11);
        tmp = get_next_line(0);
        if (ft_strncmp(tmp, argv, ft_strlen(argv)) == 0)
        {
            pipex->infile_fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 777);
            write (pipex->infile_fd, buffer, ft_strlen(buffer));
            break ;
        }
        buffer = ft_strjoin(buffer, tmp);
    }
    free(buffer);
}

// 	close(file);
// 	pipex->infile = open(".heredoc_tmp", O_RDONLY);
// 	if (pipex->infile < 0)
// 		unlink(".heredoc_tmp");