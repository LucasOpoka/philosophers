/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt_thrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:41:31 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 18:52:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	*ft_rtne_philo(void *pt)
{
	t_thrd	*thrd;

	thrd = pt;
	printf("Philo %d\n", thrd->id);
	usleep(50000);
	printf("Philo %d\n", thrd->id);
	return (pt);
}

void	*ft_rtne_monit(void *pt)
{
	t_thrd	*thrd;

	thrd = pt;
	printf("Monit %d\n", thrd->id);
	usleep(50000);
	printf("Monit %d\n", thrd->id);
	return (pt);
}

void	ft_create_thrd(t_philo *philo, int i)
{
	void	*(*rtne)(void *);

	if (i < philo->no)
		rtne = &ft_rtne_philo;
	else
		rtne = &ft_rtne_monit;
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
