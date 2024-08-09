/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt_thrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:41:31 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/09 17:59:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_create_thrd(t_philo *philo, size_t i)
{
	if (pthread_create(&(philo->thrds[i].t), NULL, &ft_routine,
			&philo->thrds[i]) != 0)
		return (ft_terminate(philo, "Error whille creating threads"), 1);
	return (0);
}

int	ft_join_thrd(t_philo *philo, size_t i)
{
	if (pthread_join(philo->thrds[i].t, NULL) != 0)
		return (ft_terminate(philo, "Error whille joining threads"), 1);
	return (0);
}

int	ft_strt_thrds(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->no)
	{
		if (ft_create_thrd(philo, i++))
			return (1);
	}
	return (0);
}

int	ft_join_thrds(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->no)
	{
		if (ft_join_thrd(philo, i++))
			return (1);
	}
	return (0);
}
