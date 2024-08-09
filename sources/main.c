/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/09 17:53:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ft_validate(ac, av, &philo))
		return (1);
	if (ft_init(&philo))
		return (1);
	if (ft_strt_thrds(&philo))
		return (1);
	ft_stop_thrds(&philo);
	if (ft_join_thrds(&philo))
		return (1);
	ft_terminate(&philo, 0);
}
