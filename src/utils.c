/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:47:52 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/21 16:00:00 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	long	nbr;
	long	neg;
	int		i;

	nbr = 0;
	neg = 1;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (nbr * neg);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if ((size * nmemb) >= SIZE_MAX)
		return (NULL);
	if ((int) nmemb < 0 && (int) size < 0)
		return (NULL);
	if ((int)(size * nmemb) < 0)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}

void	printfilo(t_phiphi *philo, char *action)
{
	pthread_mutex_lock(&philo->pdata->mu_write);
	pthread_mutex_lock(&philo->pdata->mu_death);
	if (philo->pdata->one_is_dead == false)
	{
		printf("%lu %u %s\n",ft_timeoftheday() - philo->pdata->start,
			philo->id, action);
	}
	pthread_mutex_unlock(&philo->pdata->mu_write);
	pthread_mutex_unlock(&philo->pdata->mu_death);
}

size_t	ft_timeoftheday(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_data *data, size_t milliseconds)
{
	size_t	start;

	pthread_mutex_lock(&data->mu_time);
	start = ft_timeoftheday();
	while (((ft_timeoftheday() - start) < milliseconds))
	{
		pthread_mutex_unlock(&data->mu_time);
		usleep(500);
		pthread_mutex_lock(&data->mu_time);
	}
	pthread_mutex_unlock(&data->mu_time);
	return (0);
}