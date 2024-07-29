/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:39:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/29 14:08:50 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	ft_end_all(t_philo *philo, char *s, int code)
{
	int	i;

	if (s)
		printf("%s\n", s);
	i = 1;
	while (i <= philo->no)
	{
		pthread_mutex_destroy(&philo->thrds[i].eat_lock);
		pthread_mutex_destroy(&philo->thrds[i].aux_lock);
		pthread_mutex_destroy(&philo->frks[i]);
		i++;
	}
	free(philo->thrds);
	free(philo->frks);
	pthread_mutex_destroy(&philo->prnt_lock);
	pthread_mutex_destroy(&philo->dead_lock);
	exit (code);
}
