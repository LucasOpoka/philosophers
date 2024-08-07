/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:08:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/07 13:35:54 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_wait(size_t ms, t_philo *philo)
{
	size_t	strt;
	size_t	i;

	i = 0;
	strt = get_time();
	while ((get_time() - strt) < ms)
	{
		if (i % 200 == 0)
		{
			pthread_mutex_lock(&philo->lock);
			if (philo->dead_or_full)
				return (pthread_mutex_unlock(&philo->lock), 0);
			pthread_mutex_unlock(&philo->lock);
		}
		usleep(500);
		i++;
	}
	return (1);
}

int	ft_prnt_lock(t_thrd *thrd, char *s)
{
	pthread_mutex_lock(&thrd->philo->lock);
	if (thrd->philo->dead_or_full)
		return (pthread_mutex_unlock(&thrd->philo->lock), 0);
	printf("%zu %d %s\n", get_time() - thrd->philo->strt, thrd->id, s);
	return (pthread_mutex_unlock(&thrd->philo->lock), 1);
}
