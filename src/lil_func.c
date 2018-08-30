/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:19:49 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:19:58 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		get_players(t_player *players)
{
	int	n;

	n = 0;
	while (players)
	{
		players = players->next;
		++n;
	}
	return (n);
}

int		get_processes(t_process *proc)
{
	int n;

	n = 0;
	while (proc)
	{
		++n;
		proc = proc->next;
	}
	return (n);
}

void	print_end(t_char *print)
{
	while (print)
	{
		ft_printf("%c", print->c);
		print = print->next;
	}
}
