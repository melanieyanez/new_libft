/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:02:51 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/08 14:37:52 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_in_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_in_charset(s1[start], set) == 1)
		start ++;
	while (is_in_charset(s1[end], set) == 1)
		end --;
	if (start < end)
		result = malloc(sizeof(char) * (end - start + 1 + 1));
	else
		result = malloc(1 * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (start + ++i <= end)
		result[i] = s1[start + i];
	result[i] = '\0';
	return (result);
}

/*
int	main(void)
{
	char	s1_test[] = "aaaaaa";
	char	set_test[] = "a";

	printf("%s\n", ft_strtrim(s1_test, set_test));
}
*/