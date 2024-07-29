/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtne_monit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:47:23 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/29 13:01:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_green_pastures(t_thrd *thrd)
{
	pthread_mutex_lock(&thrd->eat_lock);
	pthread_mutex_lock(&thrd->aux_lock);
	if (get_time() - thrd->lst_eat >= thrd->philo->ms_die && thrd->eating == 0)
		return (pthread_mutex_unlock(&thrd->eat_lock),
			pthread_mutex_unlock(&thrd->aux_lock), 1);
	pthread_mutex_unlock(&thrd->aux_lock);
	pthread_mutex_unlock(&thrd->eat_lock);
	return (0);
}

int	ft_check_casualties(t_thrd *thrd)
{
	int	i;

	i = 1;
	while (i <= thrd->philo->no)
	{
		if (ft_green_pastures(&thrd->philo->thrds[i]))
		{
			ft_prnt(&thrd->philo->thrds[i], "died");
			pthread_mutex_lock(&thrd->philo->dead_lock);
			thrd->philo->dead = 1;
			pthread_mutex_unlock(&thrd->philo->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_full(t_thrd *thrd)
{
	int	i;

	i = 1;
	if (thrd->philo->no_eat == -1)
		return (0);
	while (i <= thrd->philo->no)
	{
		pthread_mutex_lock(&thrd->philo->thrds[i].eat_lock);
		if (thrd->philo->thrds[i].no_ate < thrd->philo->no_eat)
			return (pthread_mutex_unlock(&thrd->philo->thrds[i].eat_lock), 0);
		pthread_mutex_unlock(&thrd->philo->thrds[i++].eat_lock);
	}
	pthread_mutex_lock(&thrd->philo->dead_lock);
	thrd->philo->dead = 1;
	pthread_mutex_unlock(&thrd->philo->dead_lock);
	return (1);
}

void	*ft_rtne_monit(void *pt)
{
	t_thrd	*thrd;

	thrd = pt;
	while (1)
	{
		if (ft_check_casualties(thrd) || ft_check_full(thrd))
			break ;
	}
	return (pt);
}
