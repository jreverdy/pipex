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
	t_command	cmd;

	if (ac != 5)
	{
		ft_putstr_fd("Wrong numbers of arguments\n", 1);
		return (-1);
	}
	return (ft_pipex(&cmd, envp, av));
}
