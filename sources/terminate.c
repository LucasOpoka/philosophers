/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:39:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/06 21:11:26 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	ft_terminate(t_philo *philo, char *s, int code)
{
	int	i;

	if (s)
		printf("%s\n", s);
	i = 0;
	while (i < philo->no)
		pthread_mutex_destroy(&philo->frks[i++]);
	free(philo->thrds);
	free(philo->frks);
	pthread_mutex_destroy(&philo->lock);
	exit (code);
}
