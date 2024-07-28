/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:08:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 21:44:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
		printf("Get time error\n");
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_wait(size_t ms)
{
	size_t	strt;

	strt = get_time();
	while ((get_time() - strt) < ms)
		usleep(500);
}

void	ft_prnt(t_thrd *thrd, char *s)
{
	pthread_mutex_lock(&thrd->philo->prnt_lock);
	if (!ft_casualties(thrd))
		printf("%zu %d %s\n", get_time() - thrd->philo->strt, thrd->id, s);
	pthread_mutex_unlock(&thrd->philo->prnt_lock);
}
