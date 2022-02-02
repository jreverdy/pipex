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

void	child_one(int f1, char **com1)
{

}

void	child_two(int f2, char **com2)
{

}

void	ft_pipex(int f1, int f2, t_command *cmd)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork :"));
	if (child1 == 0)
		child_one(f1, cmd->com1);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork :"));
	if (child2 == 0)
		child_two(f2, cmd->com2);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
