/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:26:23 by aeddaoud          #+#    #+#             */
/*   Updated: 2021/11/19 21:15:00 by aeddaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	tc;

	i = 0;
	j = 0;
	tc = (char)c;
	while (s[j])
		j++;
	while (i < j + 1)
	{
		if (s[i] == tc)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
