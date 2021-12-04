/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:45:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/04 04:16:25 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	argv_count;
	int	cmd_count;

	argv_count = 2;
	cmd_count = 0;
	t_pipex	pipex;
	/************** open infile and outfile ********/
	pipex.infile_fd = open(argv[1], O_RDWR | O_CREAT);
	pipex.outfile_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC);
	/************** parsing commands **************/
	pipex.exc_cmd = (char **)malloc(sizeof(char *) * (argc - 2));
	while (argv[argv_count])
	{
		pipex.cmd = ft_split(argv[argv_count], ' ');
		pipex.exc_cmd[cmd_count] = ft_check_excute(pipex.cmd[0], env);
		//pipex.exc_path_2 = ft_check_excute(pipex.cmd_2[0], env);
		if (argv[argv_count + 1] == NULL)
			break;
		argv_count++;
		cmd_count++;
	}
	pipex.exc_cmd[cmd_count] = NULL;
	pipex.cmd_count = 0;
	/************** excute commands **********/
	while (pipex.exc_cmd[cmd_count])
	{
		pipe(pipex.pipefd);
		if (pipex.pipefd < 0)
		{
			perror ("pipe");
			exit(1);
		}
		pipex.pid = fork();
		if (pipex.pid  == 0)
		{
			// child process;
		}
		else 
			// parent process;
	}
	return (0);
}