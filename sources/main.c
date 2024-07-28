/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 18:50:51 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	ft_validate_av(ac, av, &philo);
	ft_init(&philo);
	ft_strt_thrds(&philo);
	return (0);
}
