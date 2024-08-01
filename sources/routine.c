/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:49:11 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/01 19:49:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_grab_forks(t_thrd *thrd)
{
	if (ft_time_to_stop(thrd))
		return (0);
	pthread_mutex_lock(thrd->l_frk);
	if (!ft_prnt_lock(thrd, "has taken a fork"))
		return (pthread_mutex_unlock(thrd->l_frk), 0);
	if (ft_time_to_stop(thrd) || thrd->philo->no == 1)
		return (pthread_mutex_unlock(thrd->l_frk), 0);
	pthread_mutex_lock(thrd->r_frk);
	if (!ft_prnt_lock(thrd, "has taken a fork"))
		return (pthread_mutex_unlock(thrd->l_frk),
			pthread_mutex_unlock(thrd->r_frk), 0);
	return (1);
}

void	ft_eat(t_thrd *thrd)
{
	pthread_mutex_lock(&thrd->philo->lock);
	thrd->no_ate++;
	thrd->lst_eat = get_time();
	pthread_mutex_unlock(&thrd->philo->lock);
	ft_prnt_lock(thrd, "is eating");
	ft_wait(thrd->philo->ms_eat);
	pthread_mutex_lock(&thrd->philo->lock);
	if (thrd->no_ate == thrd->philo->no_eat && thrd->philo->no_eat != -1)
		thrd->philo->no_full++;
	pthread_mutex_unlock(&thrd->philo->lock);
	pthread_mutex_unlock(thrd->l_frk);
	pthread_mutex_unlock(thrd->r_frk);
}

int	ft_sleep_think(t_thrd *thrd)
{
	if (!ft_prnt_lock(thrd, "is sleeping"))
		return (0);
	ft_wait(thrd->philo->ms_slp);
	if (!ft_prnt_lock(thrd, "is thinking"))
		return (0);
	return (1);
}

void	*ft_routine(void *pt)
{
	t_thrd	*thrd;

	thrd = pt;
	if (thrd->id % 2 == 0)
		ft_wait(10);
	while (1)
	{
		if (!ft_grab_forks(thrd))
			break ;
		ft_eat(thrd);
		if (!ft_sleep_think(thrd))
			break ;
	}
	return (0);
}
