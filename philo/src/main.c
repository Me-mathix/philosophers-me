/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:47:09 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/29 12:58:14 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;
	
	if (argc != 5 && argc != 6)
		exit(123);
	if (check_args(&data, argv))
		exit(123);
	if (parse_args(&data))
		exit(123);
	if (launch_philo(&data))
		exit(123);
	return (0);
}