/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt_thrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:41:31 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/01 19:24:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	ft_create_thrd(t_philo *philo, int i)
{
	if (pthread_create(&(philo->thrds[i].t), NULL, &ft_routine,
			&philo->thrds[i]) != 0)
		ft_terminate(philo, "Error whille creating threads", 1);
}

void	ft_join_thrd(t_philo *philo, int i)
{
	if (pthread_join(philo->thrds[i].t, NULL) != 0)
		ft_terminate(philo, "Error whille joining threads", 1);
}

void	ft_strt_thrds(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->no)
		ft_create_thrd(philo, i++);
}

void	ft_join_thrds(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->no)
		ft_join_thrd(philo, i++);
}
