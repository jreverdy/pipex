#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_command
{
	char	**com1;
	char	**com2;
	char 	*com1_path;
	char 	*com2_path;
	char 	*path_line;
}t_command;

void	ft_pipex(int f1, int f2, char **av, char **envp);
void	ft_get_command(char **av, t_command *cmd);
void	ft_get_path(t_command *cmd, char **envp);
void 	ft_check_access(t_command *cmd, char **envp);

#endif
