/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:35:07 by aben-ham          #+#    #+#             */
/*   Updated: 2022/04/19 22:08:45 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	du_working(int affect)
{
	static int	i;

	if (affect)
		i = !i;
	return (i);
}

static void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (!du_working(0))
		{
			ft_putstr("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}

int	init_sigaction(void)
{
	if (signal(SIGINT, sig_handler) != 0)
		return (0);
	if (signal(SIGQUIT, SIG_IGN) != 0)
		return (0);
	return (1);
}
