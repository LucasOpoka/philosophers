/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:15:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/27 15:48:05 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_thrd
{

}	t_thrd;

typedef struct s_philo
{
	int				no_thrds;
	t_size			ms_die;
	t_size			ms_eat;
	t_size			ms_slp;
	int				no_eat;
	t_thrd			*thrds;
	pthread_mutex_t	*frks;
	pthread_mutex_t	die_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	prnt_lock;
	int				dead;
}	t_philo;

#endif
