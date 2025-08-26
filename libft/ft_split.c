/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:19:42 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/05/14 17:10:57 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_substr_amount(const char *s, char c)
{
	size_t	i;
	size_t	amount;

	i = 0;
	amount = 0;
	if (!s)
		return (amount);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			amount++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (amount);
}

static char	*ft_sbstr(char const *s, size_t start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

static size_t	ft_gi(const char *s, char c, size_t *in)
{
	size_t	i;
	size_t	len;

	i = *in;
	len = 0;
	if (!s)
		return (len);
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (len);
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	*in = i;
	return (len);
}

static void	*ft_free_all(char **result, size_t in)
{
	size_t	i;

	i = 0;
	while (i < in)
		free (result[i++]);
	free (result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*substr;
	size_t			i;
	size_t			len;
	size_t			in;

	result = ft_calloc((ft_substr_amount(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	in = 0;
	while (1)
	{
		len = ft_gi(s, c, &i);
		if (len == 0)
			break ;
		if (len > i)
			return (ft_free_all(result, in));
		substr = ft_sbstr(s, (i - len), len);
		if (!substr)
			return (ft_free_all(result, in));
		result[in++] = substr;
	}
	return (result);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
    const char    *str = argv[1];
    char	c = ' ';
    size_t     i = 0;
    char    **result= ft_split(str, c);
    while (result[i] != NULL)
    {
        printf("%s\n", result[i]);
        i++;
    }
    i = 0;
    while(result[i] != NULL)
    {
        free(result[i]);
        result[i] = NULL;
        i++;
    }
    free(result);
}
*/
