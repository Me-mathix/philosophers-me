/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:31:29 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/07 17:20:24 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_phiphi *data;

	data = (t_phiphi *)arg;
	pthread_mutex_lock(&data->pdata.mu_death);
	while (data->pdata.one_is_dead != true)
	{
		pthread_mutex_unlock(&data->pdata.mu_death);
		eat();
		sleep();
		think();
	}
}

int launch_philo(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->nb_pilo)
	{
		if (pthread_create(&data->philo[i].t_id, NULL, routine, &data->philo[i]))
			return (2);
		i++;
	}
	i = 0;
	while (i < data->nb_pilo) 
	{
		if (pthread_join(&data->philo[i].t_id, NULL))
			return (2);
		i++;
	}
	
	
}