/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:50:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/29 11:55:58 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	ft_usage(void)
{
	printf("Usage: philo arg1 arg2 arg3 arg4 arg5\n");
	printf("Arg	Name				Type		Range\n");
	printf("arg1	number_of_philosophers		mandatory	0 < arg1\n");
	printf("arg2	time_to_die			mandatory	0 < arg2\n");
	printf("arg3	time_to_eat			mandatory	0 < arg3\n");
	printf("arg4	time_to_sleep			mandatory	0 < arg4\n");
	printf("arg5	times_each_philo_must_eat	optional	0 <= arg5\n");
	exit(1);
}

int	ft_ptoi(const char *str, int no_zro)
{
	int	res;

	res = 0;
	while ('0' <= *str && *str <= '9')
		res = res * 10 + *str++ - 48;
	if (*str || (no_zro && res == 0))
		ft_usage();
	return (res);
}

void	ft_validate_av(int ac, char **av, t_philo *philo)
{
	if (ac < 5 || 6 < ac)
		ft_usage();
	philo->no = ft_ptoi(av[1], 1);
	philo->ms_die = ft_ptoi(av[2], 1);
	philo->ms_eat = ft_ptoi(av[3], 1);
	philo->ms_slp = ft_ptoi(av[4], 1);
	if (ac == 6)
		philo->no_eat = ft_ptoi(av[5], 0);
	else
		philo->no_eat = -1;
}
