/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeach <rbeach@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:17:32 by rbeach            #+#    #+#             */
/*   Updated: 2020/05/30 16:19:47 by rbeach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int				result;
	int				i;

	i = 0;
	if (!src)
		return (0);
	result = ft_strlen(src);
	if (!size)
		return (result);
	while (src[i] != '\0' && i < (int)size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((newstr = (char *)malloc(ft_strlen(s) + 1)))
	{
		while (s[i])
		{
			newstr[i] = s[i];
			i++;
		}
		newstr[i] = '\0';
	}
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*substr;
	unsigned int	slen;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char*)s;
	slen = ft_strlen(str);
	if (slen < start)
		return (ft_strdup(""));
	if ((substr = (char*)malloc(len + 1)))
	{
		while (len - i && *str)
		{
			substr[i] = str[(int)start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if ((s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		i = 0;
		j = 0;
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			s[i + j] = s2[j];
			j++;
		}
		s[i + j] = '\0';
	}
	return (s);
}
