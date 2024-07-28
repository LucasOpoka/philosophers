/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:15:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 18:41:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_thrd
{
	pthread_t	t;
	int			id;
	int			eating;
	int			no_ate;
	size_t		lst_eat;
	t_philo		*philo;
}	t_thrd;

typedef struct s_philo
{
	int				no;
	size_t			ms_die;
	size_t			ms_eat;
	size_t			ms_slp;
	int				no_eat;
	t_thrd			*thrds;
	pthread_mutex_t	*frks;
	pthread_mutex_t	die_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	prnt_lock;
	int				dead;
	size_t			strt;
}	t_philo;

// Validate
void	ft_validate_av(int ac, char **av, t_philo *philo);

// Init
void	ft_init(t_philo *philo);

//Strt thrds
void	ft_strt_thrds(t_philo *philo);

// Utils
size_t	get_time(void);

#endif
