/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:58:03 by melanieyane       #+#    #+#             */
/*   Updated: 2023/04/08 14:37:08 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(void)
{
	char	file_path[] = "/Users/melanieyanez/Desktop/libft/haricotvert.txt";
	int		file;

	file = open(file_path, O_RDWR);
	ft_putchar_fd('B', file);
}*/
