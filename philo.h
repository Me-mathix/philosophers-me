/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:52:50 by mda-cunh          #+#    #+#             */
/*   Updated: 2024/05/03 13:32:27 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stdlib.h"
# include "pthread.h"
# include <stddef.h>
# include <stdint.h>
# include "stdbool.h"

typedef struct s_phiphi
{
	unsigned int		id;
	pthread_t			t_id;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		r_fork;
	unsigned long		last_meal;
	long				num_meal;
	bool				dead;
}	t_phiphi;

typedef struct s_data
{
	unsigned int	nb_pilo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				requiered_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t mu_write;	
	t_phiphi		*philo;
}	t_data;

//init_args.c
int		check_args(t_data *data, char **argv);

//utils.c
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);