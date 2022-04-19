/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 01:08:48 by hbourkan          #+#    #+#             */
/*   Updated: 2022/04/16 15:59:35 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **args, int fd)
{
	char	**env;
	int		i;

	i = 0;
	env = env_var(NULL);
	if (args[0])
	{
		ft_putstr_fd(2, args[0]);
		ft_putstr_fd(2, ": No such file or directory\n");
		return (127);
	}
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			ft_putstr_fd(fd, env[i]);
			write(fd, "\n", 1);
		}
		i++;
	}
	return (0);
}
