/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/29 13:55:04 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	ft_validate_av(ac, av, &philo);
	ft_init(&philo);
	ft_strt_thrds(&philo);
	ft_end_all(&philo, 0, 0);
}
