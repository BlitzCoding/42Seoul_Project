/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:31:00 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/22 15:13:34 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INPUT_FAIL		0
# define OPEN_FAIL		1
# define PARSE_FAIL		2
# define PIPE_FAIL		3
# define FORK_FAIL		4
# define MALLOC_FAIL	5
# define EXEC_FAIL		6

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	**av_cmd1;
	char	**av_cmd2;
	char	*parse_cmd1;
	char	*parse_cmd2;
}	t_cmd;

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**envp_parse;
	int		fd1;
	int		fd2;
	int		pipes[2];
	t_cmd	cmd;
}	t_pipex;

void	print_error(int status, t_pipex *pipex);
void	do_pipex(pid_t pid, t_pipex *pipex, char **envp);
void	free_all(t_pipex *pipex);

#endif