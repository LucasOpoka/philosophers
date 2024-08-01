/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/01 19:25:33 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	ft_validate(ac, av, &philo);
	ft_init(&philo);
	ft_strt_thrds(&philo);
	ft_stop_thrds(&philo);
	ft_join_thrds(&philo);
	ft_terminate(&philo, 0, 0);
}
