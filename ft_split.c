/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelee <saelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:10:19 by saelee            #+#    #+#             */
/*   Updated: 2021/06/08 19:10:20 by saelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ')
		return (1);
	return (0);
}

size_t	ft_count(char *s, const char needle)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != needle && (s[i + 1] == needle || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_check(char *s, const char needle, int i)
{
	int	x;

	x = 0;
	while (s[i] && s[i] == needle)
		i++;
	while (s[i] && s[i] != needle)
	{
		i++;
		x++;
	}
	return (x);
}

char	*ft_estrapolate(char *s, const char needle, size_t *offset)
{
	size_t		i;
	size_t		length;
	char		*str;

	length = ft_check(s, needle, *offset);
	str = ft_calloc(length + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s[*offset] == needle)
		(*offset)++;
	while (i < length)
		str[i++] = s[(*offset)++];
	return (str);
}

char 	**ft_split(char *s, const char needle)
{
	size_t	count;
	char	**splitted;
	size_t	i;
	size_t	offset;

	if (!s)
		return (NULL);
	count = ft_count(s, needle);
	offset = 0;
	i = 0;
	splitted = ft_calloc(count + 1, sizeof(char *));
	if (splitted == 0)
		return (NULL);
	while (i < count)
	{
		splitted[i] = ft_estrapolate(s, needle, &offset);
		if (splitted[i] == 0)
			return (NULL);
		i++;
	}
	return (splitted);
}
