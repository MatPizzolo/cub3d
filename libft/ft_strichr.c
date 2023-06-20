/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpizzolo <mpizzolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:16:30 by mpizzolo          #+#    #+#             */
/*   Updated: 2023/06/20 20:51:57 by mpizzolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strichr(const char *s, int c, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (1);
		i--;
	}
	return (0);
}
