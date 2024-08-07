/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:15:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/07 14:50:03 by lopoka           ###   ########.fr       */
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
	pthread_t		t;
	int				id;
	int				no_ate;
	size_t			lst_eat;
	pthread_mutex_t	*l_frk;
	pthread_mutex_t	*r_frk;
	t_philo			*philo;
}	t_thrd;

typedef struct s_philo
{
	int				no;
	size_t			ms_die;
	size_t			ms_eat;
	size_t			ms_slp;
	int				no_eat;
	int				no_full;
	t_thrd			*thrds;
	pthread_mutex_t	*frks;
	pthread_mutex_t	lock;
	int				dead_or_full;
	size_t			strt;
}	t_philo;

// Validate
void	ft_validate(int ac, char **av, t_philo *philo);

// Init
void	ft_init(t_philo *philo);

// Routine
void	*ft_routine(void *pt);

// Strt thrds
void	ft_strt_thrds(t_philo *philo);

// Stop thrds
void	ft_stop_thrds(t_philo *philo);
int		ft_time_to_stop(t_thrd *thrd);

// Join thrds
void	ft_join_thrds(t_philo *philo);

// Utils
int		ft_prnt_lock(t_thrd *thrd, char *s);
size_t	get_time(void);
int		ft_wait(size_t ms, t_philo *philo);

// Terminate
void	ft_terminate(t_philo *philo, char *s, int code);

#endif
