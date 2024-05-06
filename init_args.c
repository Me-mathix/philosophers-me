/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:47:56 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/06 14:19:09 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_only_numeric(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
			if (!ft_isdigit(tab[i][j++]))
				return (1);
		j = 0;
		i++;
	}
	return (0);
}

int check_args(t_data *data, char **argv)
{
	if (is_only_numeric(argv))
		return (1);
	data->nb_pilo = ft_atoi(argv[1]);
	data->ttdie = ft_atoi(argv[2]);
	data->tteat = ft_atoi(argv[3]);
	data->ttsleep = ft_atoi(argv[4]);
	data->requiered_eat = -1;
	if (argv[5])
	{
		data->requiered_eat = ft_atoi(argv[5]);
		if (data->requiered_eat < 0)
			return (2);
	}
	if (data->nb_pilo <= 0 || data->ttdie <= 0 || data->tteat <= 0
		|| data->ttsleep <= 0)
		return (2);
	return (0);
}

int start_mutex(t_data *data)
{
	int i;

	i = 0;
	data->fork = ft_calloc((sizeof (pthread_mutex_t)), data->nb_pilo);
	if (!data->fork)
		return (1);
	while (i < data->nb_pilo)
	{
		if (pthread_mutex_init(&data->fork[i++], NULL))
			return (free(data->fork), 1);
	}
	if (pthread_mutex_init(&data->mu_write, NULL))
		return (free(data->fork), 1);
	return (0);	
}

void init_philo(t_data *data)
{
	int i;

	i = 0;
	while(i < data->nb_pilo)
	{
		data->philo->id = i + 1;
		data->philo->last_meal = 0;
		data->philo->r_fork = data->fork[i];
		data->philo->l_fork = data->fork[(1 + i) % data->nb_pilo];
		data->philo->num_meal = data->requiered_eat;
		data->philo->dead = false;
		i++;
	}
}

int parse_args(t_data *data, char **argv)
{
	if (start_mutex(data))
		return (1);
	data->philo = ft_calloc((sizeof (t_phiphi)), data->nb_pilo);
	if (!data->philo)
		return (2);
	init_philo(data);
	return (0);	
}