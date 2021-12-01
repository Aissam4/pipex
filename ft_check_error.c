/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:32:49 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/01 16:41:29 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

char	*ft_check_path(char **env)
{
	char	*path_line;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_line = env[i];
			return (path_line + 5);
		}
		i++;
	}
	return (NULL);
}

char	*ft_check_excute(char *cmd, char **env)
{
	int		i;
	char	**splited_path;
	char	*tmp;
	char	*finall_path;

	splited_path = ft_split(ft_check_path(env), ':');
	i = 0;
	while (splited_path[i])
	{
		if (splited_path[i][ft_strlen(splited_path[i])] != '/')
			tmp = ft_strjoin(splited_path[i], "/");
		else
			tmp = ft_strdup(splited_path[i]);
		finall_path = ft_strjoin(tmp, cmd);
		if (access(finall_path, X_OK | F_OK) == 0)
		{
			free(splited_path);
			return (finall_path);
		}
		free(finall_path);
		i++;
	}
	free(splited_path);
	return (NULL);
}
