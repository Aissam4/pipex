/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:37:56 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/01 16:40:46 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent_process(t_pipex *pipex, char **env)
{
	wait(NULL);
	close(pipex->pipefd[W]);
	dup2(pipex->pipefd[R], STDIN_FILENO);
	close(pipex->pipefd[R]);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	execve(pipex->exc_path_2, pipex->cmd_2, env);
}
