/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:19:28 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/30 14:27:12 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void exit_philo(t_data *data)
{
	unsigned int i;
	
	i = 0;
	pthread_mutex_destroy(&data->mu_death);
	pthread_mutex_destroy(&data->mu_time);
	pthread_mutex_destroy(&data->mu_write);
	pthread_mutex_destroy(&data->mu_eat);
	while (i < data->nb_pilo) 
		pthread_mutex_destroy(&data->fork[i++]);
	free(data->philo);
	free(data->fork);
}