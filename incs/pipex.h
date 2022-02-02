/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:52:43 by jereverd          #+#    #+#             */
/*   Updated: 2022/02/01 13:52:44 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <stdio.h>

typedef struct s_command
{
	char	**com1;
	char	**com2;
	char	*com1_path;
	char	*com2_path;
	char	*path_line;
	char	**path_tab;
}t_command;

void	ft_pipex(int f1, int f2, t_command *cmd);
void	ft_get_command(char **av, t_command *cmd);
void	ft_get_path(t_command *cmd, char **envp);
char	*ft_check_access(char *cmd_name, t_command *cmd, char **av);
void	ft_error(char *path, char *cmd_name, t_command *cmd, char **av);

#endif
