/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:07:36 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/25 16:07:38 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	ft_get_command(char **av, t_command *cmd)
{
	cmd->com1 = ft_split(av[2], ' ');
	cmd->com2 = ft_split(av[3], ' ');
}
