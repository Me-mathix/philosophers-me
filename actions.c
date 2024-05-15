/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:48:31 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/15 12:31:40 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_phiphi *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	printfilo(philo, "has taken a fork");
	if (philo->pdata.nb_pilo == 1)
		return ;
	pthread_mutex_lock(&philo->r_fork);
	printfilo(philo, "has taken a fork");
	pthread_mutex_lock(&philo->pdata.mu_time);
	philo->last_meal = ft_timeoftheday();
	pthread_mutex_unlock(&philo->pdata.mu_time);
	printfilo(philo, "is eating");
	philo->num_meal++;
	ft_usleep(philo->pdata.tteat);	
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void sleep(t_phiphi *philo)
{
	printfilo(philo, "is sleeping");
	ft_usleep(philo->pdata.ttsleep);
}

void think(t_phiphi *philo)
{
	printfilo(philo, "is thinking");
	ft_usleep(1);
} 