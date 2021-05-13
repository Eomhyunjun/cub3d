/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:03:22 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 07:07:42 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		signchk(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static	void	recur(int n, int fd)
{
	char	pnt;

	if (n >= 10)
		recur(n / 10, fd);
	pnt = '0' + (n % 10);
	write(fd, &pnt, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	sign = signchk(n);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (sign < 0)
		write(fd, "-", 1);
	recur(n * sign, fd);
}
