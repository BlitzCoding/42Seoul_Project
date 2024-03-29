/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuhan <seuhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:52:00 by seuhan            #+#    #+#             */
/*   Updated: 2022/08/01 00:46:46 by seuhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find_in_env(t_minishell *data, char *var_env)
{
	int	j;

	j = 0;
	while (data->new_env[j])
	{
		if ((!ft_strncmp(data->new_env[j], var_env, ft_strlen(var_env)) \
			&& data->new_env[j][ft_strlen(var_env)] == '=') \
		|| (!ft_strncmp(data->new_env[j], var_env, ft_strlen(var_env))
			&& data->new_env[j][ft_strlen(var_env)] == '\0'))
			break ;
		j++;
	}
	return (j);
}

void	do_first_cmd(t_lst_cmd	*lst_cmd)
{
	int	out;

	if (lst_cmd->fd_in != -1)
	{
		dup2(lst_cmd->fd_in, STDIN_FILENO);
		close(lst_cmd->fd_in);
	}
	if (lst_cmd->fd_out != -1)
		out = lst_cmd->fd_out;
	else
		out = lst_cmd->pipe_fd[1];
	dup2(out, STDOUT_FILENO);
	close(out);
	close(lst_cmd->pipe_fd[0]);
}

void	do_mid_cmd(t_lst_cmd	*lst_cmd)
{
	int	in;
	int	out;

	if (lst_cmd->fd_in != -1 && lst_cmd)
		in = lst_cmd->fd_in;
	else
		in = lst_cmd->prev->pipe_fd[0];
	if (lst_cmd->fd_out != -1 && lst_cmd)
		out = lst_cmd->fd_out;
	else
		out = lst_cmd->pipe_fd[1];
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(out);
	close(in);
	close(lst_cmd->pipe_fd[0]);
	close(lst_cmd->pipe_fd[1]);
}

void	do_last_cmd(t_lst_cmd	*lst_cmd)
{
	int	in;

	if (lst_cmd->fd_in != -1 && lst_cmd)
		in = lst_cmd->fd_in;
	else
		in = lst_cmd->prev->pipe_fd[0];
	if (lst_cmd->fd_out != -1)
	{
		dup2(lst_cmd->fd_out, STDOUT_FILENO);
		close(lst_cmd->fd_out);
	}
	dup2(in, STDIN_FILENO);
	close(in);
}

void	init_dup(t_lst_cmd *lst_cmd)
{
	if (lst_cmd->prev == NULL && lst_cmd->next != NULL)
		do_first_cmd(lst_cmd);
	if (lst_cmd->prev != NULL && lst_cmd->next != NULL)
		do_mid_cmd(lst_cmd);
	if (lst_cmd->prev != NULL && lst_cmd->next == NULL)
		do_last_cmd(lst_cmd);
	if (lst_cmd->prev == NULL && lst_cmd->next == NULL)
	{
		if (lst_cmd->fd_in != -1)
		{
			dup2(lst_cmd->fd_in, STDIN_FILENO);
			close(lst_cmd->fd_in);
		}
		if (lst_cmd->fd_out != -1)
		{
			dup2(lst_cmd->fd_out, STDOUT_FILENO);
			close(lst_cmd->fd_out);
		}
	}
}
