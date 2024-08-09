/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:50:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/08/09 17:59:49 by lucas            ###   ########.fr       */
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
	printf("arg5	times_each_philo_must_eat	optional	0 < arg5\n");
	exit(1);
}

int	ft_ptoi(const char *str, size_t *num)
{
	size_t	res;

	res = 0;
	while ('0' <= *str && *str <= '9')
		res = res * 10 + *str++ - 48;
	if (*str || res == 0)
		return (ft_usage(), 1);
	*num = res;
	return (0);
}

int	ft_validate(int ac, char **av, t_philo *philo)
{
	if (ac < 5 || 6 < ac)
		return (ft_usage(), 1);
	if (ft_ptoi(av[1], &philo->no))
		return (ft_usage(), 1);
	if (ft_ptoi(av[2], &philo->ms_die))
		return (ft_usage(), 1);
	if (ft_ptoi(av[3], &philo->ms_eat))
		return (ft_usage(), 1);
	if (ft_ptoi(av[4], &philo->ms_slp))
		return (ft_usage(), 1);
	philo->no_eat = 0;
	if (ac == 6 && ft_ptoi(av[5], &philo->no_eat))
		return (ft_usage(), 1);
	return (0);
}
