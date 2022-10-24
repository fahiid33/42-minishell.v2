/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:52:02 by fstitou           #+#    #+#             */
/*   Updated: 2022/10/23 05:03:05 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_files(int exe, int fin, int fout)
{
	if (!exe)
	{
		if (!g_vars.g_err)
		{
			if (fin != 0)
				dup2(fin, 0);
			if (fout != 1)
				dup2(fout, 1);
		}
	}
}

void	file_error(char *filename, int am)
{
	if (am)
		g_vars.g_err = 1;
	ft_putstr_fd("minishell: no such file or directory: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putchar_fd('\n', 2);
	g_vars.exit_status = 1;
}

void	wrong_cmd_helper(char *error, int w)
{
	if (w)
	{
		(void)error;
		g_vars.exit_status = 1;
		exit(g_vars.exit_sig);
	}
	else
	{
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		g_vars.exit_status = 126;
		exit(g_vars.exit_status);
	}
}

int	ambg_redir(char *file)
{
	if (file[0] == '\0')
		file_error("", 1);
	else
		errors(4);
	return (2);
}
