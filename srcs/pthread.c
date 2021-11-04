/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:15:00 by bahn              #+#    #+#             */
/*   Updated: 2021/11/04 21:45:28 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo, int limit)
{
	int i;

	i = 0;
	while (i++ < limit)
	{	
		usleep(1000);
		gettimeofday(&timestamp.end, NULL);
		philo->time_to_die--;
		printf("%ldms : [%d] is eating\n", (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000, philo->id);
	}
	philo->must_eat--;
	return_fork(philo->table, philo->id);
	sleeping(philo, philo->table->time_to_sleep);
}

void	sleeping(t_philo *philo, int limit)
{
	int i;

	i = 0;
	while (i++ < limit)
	{
		usleep(1000);
		gettimeofday(&timestamp.end, NULL);
		philo->time_to_die--;
		printf("%ldms : [%d] is sleeping\n", (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000, philo->id);
	}
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	if (taken_fork(philo->table, philo->id) == SUCCESS)
		eating(philo, philo->table->time_to_eat);
	else
	{	
		usleep(1000);
		philo->time_to_die--;
		gettimeofday(&timestamp.end, NULL);
		printf("%ldms : [%d] is thinking\n", (timestamp.end.tv_usec - timestamp.start.tv_usec) / 1000, philo->id);
		thinking(philo);
	}
}
