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
#include <stdio.h>

int main(int ac, char **av, char **envp)
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
	ft_get_command(av, &cmd); // recuperer les commandes utilisées
	ft_get_path(&cmd, envp); //recuperer la ligne PATH dans la variable d'ENV (substr)
	ft_split(cmd.path_line, ':'); // creer un tableau de tableau de tous mes chemins
	//	ft_check_access(&cmd, envp)// faire une fonction pour verifier si le path est bon
	//	ft_new_path(&cmd, envp);	strjoin le / et le nom de la commande
	ft_pipex(f1, f2, av, envp); // creer les pipes et fork
}
