/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:07:48 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/25 16:07:50 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	child_one(t_command *cmd, int end[2], char **envp, char **av)
{
	close(end[0]);
	cmd->f1 = open(av[1], O_RDONLY);
	if (cmd->f1 < 0)
	{
		perror("open ");
		exit (1);
	}
	cmd->com1_path = ft_check_access(*cmd->com1, cmd, av);
	if (dup2(cmd->f1, STDIN_FILENO) < 0)
		perror("dup2 : ");
	close(cmd->f1);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		perror("dup2 : ");
	close(end[1]);
	if (cmd->com1_path)
		execve(cmd->com1_path, cmd->com1, envp);
	exit (1);
}

int	child_two(t_command *cmd, int end[2], char **envp, char **av)
{
	close(end[1]);
	cmd->f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (cmd->f2 < 0)
	{
		perror("open ");
		exit (1);
	}
	cmd->com2_path = ft_check_access(*cmd->com2, cmd, av);
	if (dup2(cmd->f2, STDOUT_FILENO) < 0)
		perror("dup2 : ");
	close(cmd->f2);
	if (dup2(end[0], STDIN_FILENO) < 0)
		perror("dup2 : ");
	close(end[0]);
	if (cmd->com2_path)
		execve(cmd->com2_path, cmd->com2, envp);
	exit (1);
}

int	ft_pipex(t_command *cmd, char **envp, char **av)
{
	int		end[2];
	int		status;

	ft_get_command(av, cmd);
	cmd->path_line = ft_get_path(envp);
	cmd->path_tab = ft_split(cmd->path_line, ':');
	pipe(end);
	if (pipe(end) == -1)
		return (-1);
	cmd->child1 = fork();
	if (cmd->child1 < 0)
		perror("Fork : ");
	if (cmd->child1 == 0)
		child_one(cmd, end, envp, av);
	cmd->child2 = fork();
	if (cmd->child2 < 0)
		perror("Fork : ");
	if (cmd->child2 == 0)
		child_two(cmd, end, envp, av);
	close(end[0]);
	close(end[1]);
	waitpid(cmd->child1, &status, 0);
	waitpid(cmd->child2, &status, 0);
	return (WEXITSTATUS(status));
}
