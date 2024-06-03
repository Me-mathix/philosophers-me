/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:52:50 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/06/03 15:18:37 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "stdlib.h"
# include "pthread.h"
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include "stdbool.h"
# include <sys/time.h>
# include <unistd.h>

typedef struct s_phiphi
{
	unsigned int		id;
	pthread_t			t_id;
	unsigned int		l_fork;
	unsigned int		r_fork;
	unsigned long		last_meal;
	long				num_meal;
	bool				dead;
	struct s_data		*pdata;
}	t_phiphi;

typedef struct s_data
{
	unsigned long	start;
	unsigned int	nb_pilo;
	unsigned int	ttdie;
	unsigned int	tteat;
	unsigned int	ttsleep;
	int				requiered_eat;
	bool			one_is_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mu_write;
	pthread_mutex_t	mu_death;
	pthread_mutex_t	mu_time;
	pthread_mutex_t	mu_eat;
	t_phiphi		*philo;
}	t_data;

//init_args.c
int				check_args(t_data *data, char **argv);
int				parse_args(t_data *data);

//exec_philo.c
int				launch_philo(t_data *data);

//utils.c
unsigned int	ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_timeoftheday(void);
void			printfilo(t_phiphi *philo, char *action);
int				ft_usleep(t_data *data, size_t milliseconds);

//utils2.c
void			ft_bzero(void *s, size_t n);

//action.c
void			dying(t_phiphi *philo);
void			eat(t_phiphi *philo);
void			ph_sleep(t_phiphi *philo);
void			think(t_phiphi *philo);

// exit.c
void			exit_philo(t_data *data);

// error_handle.c
void			ft_exit_error(int err);

#endif