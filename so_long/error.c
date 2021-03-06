/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:27:52 by yonghlee          #+#    #+#             */
/*   Updated: 2022/06/27 18:49:11 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, &(*s), 1);
		s++;
	}
}

void	print_error(char *mes)
{
	ft_putstr_fd(mes, 1);
	exit(0);
}
