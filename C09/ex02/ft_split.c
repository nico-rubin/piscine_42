/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:58:34 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/28 18:22:13 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		ft_check_sep(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

int		ft_count_words(char *str, char *sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_check_sep(str[i], sep) && (ft_check_sep(str[i + 1], sep)
					|| str[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

char	*ft_ndup(char *str, char *sep)
{
	int		size;
	int		i;
	char	*dest;

	size = 0;
	while (!ft_check_sep(str[size], sep) && str[size])
		size++;
	if (!(dest = (char *)malloc(sizeof(*dest) * (size + 1))))
		return (NULL);
	i = 0;
	while (!ft_check_sep(str[i], sep) && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;
	int		j;

	if (!(ret = (char **)malloc(sizeof(*ret) *
		(ft_count_words(str, charset) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_check_sep(str[i], charset))
		{
			ret[j] = ft_ndup(&str[i], charset);
			j++;
			while (!ft_check_sep(str[i], charset) && str[i + 1])
				i++;
		}
		i++;
	}
	ret[j] = 0;
	return (ret);
}
