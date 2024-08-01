/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:08:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/01 17:02:32 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_wait(size_t ms)
{
	size_t	strt;

	strt = get_time();
	while ((get_time() - strt) < ms)
		usleep(500);
}

int	ft_prnt_lock(t_thrd *thrd, char *s)
{
	pthread_mutex_lock(&thrd->philo->lock);
	if (thrd->philo->dead_or_full)
		return (pthread_mutex_unlock(&thrd->philo->lock), 0);
	printf("%zu %d %s\n", get_time() - thrd->philo->strt, thrd->id, s);
	return (pthread_mutex_unlock(&thrd->philo->lock), 1);
}
