/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:48:31 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/06/03 15:16:55 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dying(t_phiphi *philo)
{
	printfilo(philo, "is dead");
	pthread_mutex_lock(&philo->pdata->mu_death);
	philo->pdata->one_is_dead = true;
	pthread_mutex_unlock(&philo->pdata->mu_death);
}

void	eat(t_phiphi *philo)
{
	t_data	*data;

	data = philo->pdata;
	if (philo->id % 2)
		pthread_mutex_lock(&data->fork[philo->l_fork]);
	else
		pthread_mutex_lock(&data->fork[philo->r_fork]);
	printfilo(philo, "has taken a fork");
	if (philo->pdata->nb_pilo == 1)
		return ((void) pthread_mutex_unlock(&data->fork[philo->l_fork]));
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&data->fork[philo->l_fork]);
	else
		pthread_mutex_lock(&data->fork[philo->r_fork]);
	printfilo(philo, "has taken a fork");
	pthread_mutex_lock(&data->mu_time);
	philo->last_meal = ft_timeoftheday();
	pthread_mutex_unlock(&data->mu_time);
	printfilo(philo, "is eating");
	pthread_mutex_lock(&data->mu_eat);
	philo->num_meal++;
	pthread_mutex_unlock(&data->mu_eat);
	ft_usleep(philo->pdata, philo->pdata->tteat);
	pthread_mutex_unlock(&data->fork[philo->r_fork]);
	pthread_mutex_unlock(&data->fork[philo->l_fork]);
}

void	ph_sleep(t_phiphi *philo)
{
	printfilo(philo, "is sleeping");
	ft_usleep(philo->pdata, philo->pdata->ttsleep);
}

void	think(t_phiphi *philo)
{
	printfilo(philo, "is thinking");
	ft_usleep(philo->pdata, 1);
}
