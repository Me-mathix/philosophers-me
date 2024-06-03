/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:36:22 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/06/03 15:23:50 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	ft_exit_error(int err)
{
	if (err == 0)
		ft_putendl_fd("Wrong count of arguments", 2);
	if (err == 1)
		ft_putendl_fd("a value is NULL or forbidden", 2);
	if (err == 2)
		ft_putendl_fd("Failed to initalize philo", 2);
}
