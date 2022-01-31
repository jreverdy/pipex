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

void	ft_check_access(t_command *cmd, char **envp)
{
	int	i;

	i = -1;
	if (access(envp, R_OK) == 0)
		return (ft_strdup(envp));
}