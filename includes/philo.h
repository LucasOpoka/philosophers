/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:15:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/30 14:51:50 by lopoka           ###   ########.fr       */
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
	int				eating;
	int				no_ate;
	size_t			lst_eat;
	pthread_mutex_t	eat_lock;	
	pthread_mutex_t	aux_lock;
	t_philo			*philo;
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
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	prnt_lock;
	int				dead;
	size_t			strt;
}	t_philo;

// Validate
void	ft_validate_av(int ac, char **av, t_philo *philo);

// Init
void	ft_init(t_philo *philo);

// Routines
void	*ft_rtne_philo(void *pt);
void	*ft_rtne_monit(void *pt);

// Checks
int	ft_check_full(t_thrd *thrd);
int	ft_check_casualties(t_thrd *thrd);

//Strt thrds
void	ft_strt_thrds(t_philo *philo);

// Utils
int		ft_casualties(t_thrd *thrd);
size_t	get_time(void);
void	ft_prnt(t_thrd *thrd, char *s);
void	ft_wait(size_t ms);
void	ft_end_all(t_philo *philo, char *s, int code);

#endif
