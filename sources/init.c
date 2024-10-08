/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:16:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/09 18:17:24 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	ft_alloc(t_philo *philo)
{
	philo->thrds = malloc(philo->no * sizeof(t_thrd));
	if (!philo->thrds)
		return (printf("Failed to allocate threads\n"), 1);
	philo->frks = malloc(philo->no * sizeof(pthread_mutex_t));
	if (!philo->frks)
	{
		free(philo->thrds);
		return (printf("Failed to allocate mutexes\n"), 1);
	}
	return (0);
}

void	ft_init_philocks(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->no)
		pthread_mutex_init(&philo->frks[i++], NULL);
	pthread_mutex_init(&philo->lock, NULL);
}

void	ft_init_thrds(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->no)
	{
		philo->thrds[i].id = i + 1;
		philo->thrds[i].no_ate = 0;
		philo->thrds[i].philo = philo;
		philo->thrds[i].l_frk = &philo->frks[i];
		philo->thrds[i].r_frk = &philo->frks[(i + 1) % philo->no];
		philo->thrds[i++].lst_eat = philo->strt;
	}
}

int	ft_init(t_philo *philo)
{
	if (ft_alloc(philo))
		return (1);
	ft_init_philocks(philo);
	philo->dead_or_full = 0;
	philo->no_full = 0;
	philo->strt = get_time();
	ft_init_thrds(philo);
	return (0);
}
