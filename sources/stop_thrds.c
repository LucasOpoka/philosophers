/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_thrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:47:23 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/07 19:50:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_stop_sub(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->no)
	{
		pthread_mutex_lock(&philo->lock);
		if ((get_time() - philo->thrds[i].lst_eat >= philo->ms_die)
			|| philo->no_full == philo->no)
		{
			philo->dead_or_full = 1;
			if (philo->no_eat != -1 && philo->no_full == philo->no)
				printf("Every philosopher ate %d times\n", philo->no_eat);
			else
				printf("%zu %d died\n", get_time() - philo->strt, i + 1);
			return (pthread_mutex_unlock(&philo->lock), 1);
		}
		i++;
		pthread_mutex_unlock(&philo->lock);
	}
	return (0);
}

void	ft_stop_thrds(t_philo *philo)
{
	while (1)
	{
		if (ft_stop_sub(philo))
			break ;
	}
}

int	ft_time_to_stop(t_thrd *thrd)
{
	pthread_mutex_lock(&thrd->philo->lock);
	if (thrd->philo->dead_or_full)
		return (pthread_mutex_unlock(&thrd->philo->lock), 1);
	return (pthread_mutex_unlock(&thrd->philo->lock), 0);
}
