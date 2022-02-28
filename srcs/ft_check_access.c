/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:50:17 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/26 12:50:32 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	ft_error(char *path, char *cmd_name, t_command *cmd, char **av)
{
	if (access(path, 0) == -1 && cmd_name == cmd->com1[0])
	{
		ft_putstr_fd("Command not found : ", 1);
		ft_putstr_fd(av[2], 1);
		ft_putstr_fd("\n", 1);
		return ;
	}
	else if (access(path, 0) == -1 && cmd_name == cmd->com2[0])
	{
		ft_putstr_fd("Command not found : ", 1);
		ft_putstr_fd(av[3], 1);
		ft_putstr_fd("\n", 1);
		exit(127);
	}
}

char	*ft_check_access(char *cmd_name, t_command *cmd, char **av)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	if (access(cmd_name, X_OK) == 0)
		return (ft_strdup(cmd_name));
	while (cmd->path_tab && cmd->path_tab[i])
	{
		temp = ft_strjoin(cmd->path_tab[i], "/");
		path = ft_strjoin(temp, &cmd_name[0]);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		else
		{
			free(path);
			path = NULL;
		}
		i++;
	}
	ft_error(path, cmd_name, cmd, av);
	return (NULL);
}
