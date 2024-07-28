/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtne_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:49:11 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 23:48:59 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	ft_eat(t_thrd *thrd)
{
	if (thrd->philo->no == 1)
		return (ft_wait(thrd->philo->ms_die));
	pthread_mutex_lock(&thrd->philo->frks[thrd->id]);
	ft_prnt(thrd, "has taken a fork");
	pthread_mutex_lock(&thrd->philo->frks[(thrd->id % thrd->philo->no) + 1]);
	ft_prnt(thrd, "has taken a fork");
	pthread_mutex_lock(&thrd->aux_lock);
	thrd->eating = 1;
	pthread_mutex_unlock(&thrd->aux_lock);
	pthread_mutex_lock(&thrd->eat_lock);
	ft_prnt(thrd, "is eating");
	ft_wait(thrd->philo->ms_eat);
	thrd->lst_eat = get_time();
	thrd->no_ate++;
	pthread_mutex_unlock(&thrd->eat_lock);
	pthread_mutex_lock(&thrd->aux_lock);
	thrd->eating = 0;
	pthread_mutex_unlock(&thrd->aux_lock);
	pthread_mutex_unlock(&thrd->philo->frks[thrd->id]);
	pthread_mutex_unlock(&thrd->philo->frks[(thrd->id % thrd->philo->no) + 1]);
}

void	ft_sleep(t_thrd *thrd)
{
	ft_prnt(thrd, "is sleeping");
	ft_wait(thrd->philo->ms_slp);
}

void	ft_think(t_thrd *thrd)
{
	ft_prnt(thrd, "is thinking");
}

void	*ft_rtne_philo(void *pt)
{
	t_thrd	*thrd;

	thrd = pt;
	if (thrd->id % 2 != 0)
		usleep(1);
	while (!ft_casualties(thrd))
	{
		ft_eat(thrd);
		ft_sleep(thrd);
		ft_think(thrd);
	}
	return (pt);
}
