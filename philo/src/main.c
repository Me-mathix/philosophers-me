/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:47:09 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/06/03 15:24:58 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	err = 0;
	if (argc != 5 && argc != 6)
		return (ft_exit_error(0), 1);
	err = check_args(&data, argv);
	if (err)
		return (ft_exit_error(err), 1);
	err = parse_args(&data);
	if (err)
		return (ft_exit_error(err), 1);
	err = launch_philo(&data);
	if (err)
		return (ft_exit_error(err), 1);
	return (0);
}
