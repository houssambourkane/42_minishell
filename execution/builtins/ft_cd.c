/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 01:08:47 by hbourkan          #+#    #+#             */
/*   Updated: 2022/04/16 16:40:15 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **args, int fd)
{
	char	*path;

	if (!args[0])
		path = ft_getenv("HOME");
	else if (ft_strcmp(args[0], "~"))
		path = ft_getenv("HOME");
	else if (ft_strcmp(args[0], "-"))
	{
		path = ft_getenv("OLDPWD");
		if (!path)
		{
			ft_putstr_fd(2, "OLDPWD not set\n");
			return (1);
		}
		ft_putstr_fd(fd, path);
		write(fd, "\n", 1);
	}
	else
		path = ft_strdup(args[0]);
	if (chdir(path) == -1)
	{
		perror("Directory not found");
		return (1);
	}
	return (0);
}
