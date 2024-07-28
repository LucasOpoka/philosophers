/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:16:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 18:50:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	ft_err_exit(char *s)
{
	printf("%s\n", s);
	exit (1);
}

void	ft_alloc(t_philo *philo)
{
	philo->thrds = malloc((philo->no + 1) * sizeof(t_thrd));
	if (!philo->thrds)
		ft_err_exit("Failed to allocate threads\n");
	philo->frks = malloc(philo->no * sizeof(pthread_mutex_t));
	if (!philo->frks)
	{
		free(philo->thrds);
		ft_err_exit("Failed to allocate mutexes\n");
	}
}

void	ft_init_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->no)
		pthread_mutex_init(&philo->frks[i++], NULL);
	pthread_mutex_init(&philo->die_lock, NULL);
	pthread_mutex_init(&philo->eat_lock, NULL);
	pthread_mutex_init(&philo->prnt_lock, NULL);
}

void	ft_init_thrds(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->no)
	{
		philo->thrds[i].id = i;
		philo->thrds[i].eating = 0;
		philo->thrds[i].no_ate = 0;
		philo->thrds[i].philo = philo;
		philo->thrds[i++].lst_eat = philo->strt;
	}
}

void	ft_init(t_philo *philo)
{
	ft_alloc(philo);
	ft_init_mutexes(philo);
	philo->dead = 0;
	philo->strt = get_time();
	ft_init_thrds(philo);
}
