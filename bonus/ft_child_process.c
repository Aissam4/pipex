/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:20:01 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/05 00:46:37 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **env, t_pipex *pipex)
{
	if (pipe(pipex->pipefd) == -1)
		perror("pipe");
	pipex->pid = fork();
	if (pipex->pid == -1)
		perror("fork");
	if (pipex->pid == 0)
	{
		close(pipex->pipefd[R]);
		dup2(pipex->pipefd[W], STDOUT_FILENO);
		execve(pipex->exc_cmd, pipex->cmd, env);
	}
	else
	{
		close(pipex->pipefd[W]);
		dup2(pipex->pipefd[R], STDIN_FILENO);
		wait(NULL);
	}
}
