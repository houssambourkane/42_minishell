/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 01:08:17 by hbourkan          #+#    #+#             */
/*   Updated: 2022/04/16 17:41:30 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compare_keys(char *arg, char *s)
{
	char	*temp;

	if (ft_strchr(s, '='))
		temp = ft_substr(s, 0, equal_position(s));
	else
		temp = ft_strdup(s);
	if (ft_strcmp(arg, temp))
		return (1);
	return (0);
}

int	able_to_unset(char **args, char *s)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (check_vn(args[i]))
		{
			if (compare_keys(args[i], s))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	warning(char **args)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (args[i])
	{
		if (!check_vn(args[i]))
		{
			flag = 1;
			ft_putstr_fd(2, args[i]);
			ft_putstr_fd(2, ": not a valid identifier\n");
		}
		i++;
	}
	return (flag);
}

int	ft_unset(char **args)
{
	char	**env;
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = env_var(NULL);
	new_env = malloc(sizeof(char *) * (counter(env) + 1));
	while (env[j])
	{
		if (!able_to_unset(args, env[j]))
		{
			free(env[j]);
			j++;
			continue ;
		}
		new_env[i++] = env[j++];
	}
	new_env[i] = NULL;
	free(env);
	env_var(new_env);
	return (warning(args));
}
