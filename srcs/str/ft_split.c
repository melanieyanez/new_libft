/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:47:29 by myanez-p          #+#    #+#             */
/*   Updated: 2023/04/08 14:37:19 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	free_malloc(char **result, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		free(result[j]);
		j ++;
	}
}

size_t	nb_substr(char const *s, char c)
{
	size_t	i;
	size_t	nb;
	size_t	size;

	i = 0;
	nb = 0;
	size = ft_strlen(s);
	if (size == 0)
		return (0);
	if (s[i] != c)
		nb = 1;
	while (i < size - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			nb ++;
		i ++;
	}
	return (nb);
}

char	*substr_gen(char const *s, char c, size_t *index)
{
	char	*sub_result;
	size_t	size;
	size_t	i;

	size = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	while (s[*index + size] && s[*index + size] != c)
		size ++;
	sub_result = malloc(sizeof(*s) * (size + 1));
	if (!sub_result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sub_result[i] = s[*index];
		i ++;
		(*index)++;
	}
	sub_result[i] = '\0';
	return (sub_result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**result;

	result = malloc((nb_substr(s, c) + 1) * sizeof(s));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_substr(s, c))
	{
		result[i] = substr_gen(s, c, &j);
		if (!result[i])
		{
			free_malloc(result, i);
			free(result);
			return (NULL);
		}
		i ++;
	}
	result[i] = 0;
	return (result);
}

/*
int	main(void)
{
	int	i;
	char	**result;
	
	i = 0;
	result= ft_split("hello!zzzzzzzz", 'z');
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		i ++;
	}
	printf("%s\n", result[i]);
	return (0);
}
*/