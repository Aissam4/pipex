/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:36:33 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/03 08:40:32 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     ft_pipex(t_pipex *pipex, char **env)
{
    if (pipe(pipex->pipefd) == -1)
        {
            perror("pipe");
            exit(1);
        }
        pipex->pid = fork();
        if (pipex->pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pipex->pid == 0)
            ft_child_process(pipex, env);
        else
            ft_parent_process(pipex, env);
        
        close (pipex->infile_fd);
        close (pipex->outfile_fd);
        return (1);
}