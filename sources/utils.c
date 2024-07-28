/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:08:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/07/28 16:21:39 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
		printf("Get time error\n");
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
