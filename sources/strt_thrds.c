/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt_thrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:41:31 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/29 12:34:03 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_casualties(t_thrd *thrd)
{
	pthread_mutex_lock(&thrd->philo->dead_lock);
	if (thrd->philo->dead)
		return (pthread_mutex_unlock(&thrd->philo->dead_lock), 1);
	return (pthread_mutex_unlock(&thrd->philo->dead_lock), 0);
}

void	ft_create_thrd(t_philo *philo, int i)
{
	void	*(*rtne)(void *);

	if (i == 0)
		rtne = &ft_rtne_monit;
	else
		rtne = &ft_rtne_philo;
	if (pthread_create(&(philo->thrds[i].t), NULL, rtne, &philo->thrds[i]) != 0)
		printf("HANDLE THREAD CREATE ERROR\n");
}

void	ft_join_thrd(t_philo *philo, int i)
{
	if (pthread_join(philo->thrds[i].t, NULL) != 0)
		printf("HANDLE THREAD JOIN ERROR\n");
}

void	ft_strt_thrds(t_philo *philo)
{
	int		i;

	i = 0;
	while (i <= philo->no)
		ft_create_thrd(philo, i++);
	i = 0;
	while (i <= philo->no)
		ft_join_thrd(philo, i++);
}
