/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:31:29 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/29 15:18:59 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_for_other_case(t_data *data)
{
	unsigned int count;
	unsigned int i;

	count = 0;
	i = 0;
	while (i < data->nb_pilo)
	{
		pthread_mutex_lock(&data->mu_eat);
		if (data->philo[i].num_meal == data->requiered_eat)
			count++;
		pthread_mutex_unlock(&data->mu_eat);
		i++;
	}
	if (count == data->nb_pilo)
		return (1);
	return (0);
}

void	check_for_death(t_data *data)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_lock(&data->mu_death);
	while (data->one_is_dead == false)
	{
		pthread_mutex_unlock(&data->mu_death);
		if (i == data->nb_pilo)
			i = 0;
		pthread_mutex_lock(&data->mu_time);
		if (ft_timeoftheday() - data->philo[i].last_meal > data->ttdie)
		{
			pthread_mutex_unlock(&data->mu_time);
			printfilo(data->philo, "is dead");
			pthread_mutex_lock(&data->mu_death);
			data->one_is_dead = true;
			pthread_mutex_unlock(&data->mu_death);
			break ;
		}
		pthread_mutex_unlock(&data->mu_time);
		if (check_for_other_case(data))
			break ;
		i++;
		pthread_mutex_lock(&data->mu_death);
	}
}

void	*routine(void *arg)
{
	t_phiphi *data;

	data = (t_phiphi *)arg;
	if ((data->id - 1) % 2)
		ft_usleep(data->pdata, 1);
	pthread_mutex_lock(&data->pdata->mu_death);
	while (data->pdata->one_is_dead == false)
	{
		pthread_mutex_unlock(&data->pdata->mu_death);
		eat(data);
		if ((data->num_meal == data->pdata->requiered_eat 
			&& data->pdata->requiered_eat != -1) || data->pdata->nb_pilo == 1)
			return (NULL);
		ph_sleep(data);
		think(data);
		pthread_mutex_lock(&data->pdata->mu_death);
	}
	pthread_mutex_unlock(&data->pdata->mu_death);
	return (NULL);
}

int launch_philo(t_data *data)
{
	unsigned int i;	
	
	i = 0;
	data->start = ft_timeoftheday();
	while (i < data->nb_pilo)
	{
		if (pthread_create(&data->philo[i].t_id, NULL, routine, &data->philo[i]))
			return (2);
		pthread_mutex_lock(&data->mu_time);
		data->philo[i].last_meal = ft_timeoftheday();
		pthread_mutex_unlock(&data->mu_time);
		i++;
	}
	check_for_death(data);
	i = 0;
	while (i < data->nb_pilo)
	{
		if (pthread_join(data->philo[i].t_id, NULL))
			return (2);
		i++;
	}
	pthread_mutex_destroy(&data->mu_death);
	pthread_mutex_destroy(&data->mu_time);
	pthread_mutex_destroy(&data->mu_write);
	pthread_mutex_destroy(&data->mu_eat);
	for (size_t i = 0; i < data->nb_pilo; i++) 
		pthread_mutex_destroy(&data->fork[i]);
	return(0);
}
