/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:07:42 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/25 16:07:43 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int			f1;
	int			f2;
	t_command	cmd;

	if (ac != 5)
	{
		ft_putstr("Wrong numbers of arguments\n");
		return (-1);
	}
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	ft_get_command(av, &cmd);
	ft_get_path(&cmd, envp);
	cmd.path_tab = ft_split(*envp, ':');
	cmd.com1_path = ft_check_access(*cmd.com1, &cmd, av);
	cmd.com2_path = ft_check_access(*cmd.com2, &cmd, av);
	printf("%s\n", cmd.com1_path);
	printf("%s\n", cmd.com2_path);
//	ft_pipex(f1, f2, &cmd);
	return (0);
}
