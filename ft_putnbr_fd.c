/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:20:40 by rdavurov          #+#    #+#             */
/*   Updated: 2024/04/09 10:39:20 by rdavurov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp[11];
	int		i;

	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		n = write(fd, "-2147483648", 11) - 11;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	while (n > 0)
	{
		tmp[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
		write(fd, &tmp[i--], 1);
}