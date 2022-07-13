/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:01:38 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/10 19:14:37 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	newline_idx(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

int	ft_get_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_strjoin(char *s1, char *s2)
{
	char		*res;
	int			i;
	int			j;
	const char	*s = "";

	if (s1 == 0)
		s1 = (char *)s;
	res = malloc((ft_get_strlen(s1) + ft_get_strlen(s2) + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = 0;
	if (s1 != s)
		free(s1);
	return (res);
}