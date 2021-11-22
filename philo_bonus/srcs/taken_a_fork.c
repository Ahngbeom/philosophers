/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taken_a_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:20:22 by bahn              #+#    #+#             */
/*   Updated: 2021/11/21 11:34:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int taken_a_fork(t_philo *philo)
{
    if (philo->table->number_of_philos == 1)
    {
        pthread_mutex_lock(&philo->table->fork_mutex[philo->id - 1]);
        ft_print(philo->table, philo->id, "has taken a fork");
        while (philo->table->died_philos == 0)
            usleep(10);
        pthread_mutex_unlock(&philo->table->fork_mutex[philo->id - 1]);
        return (1);
    }
    pthread_mutex_lock(&philo->table->fork_mutex[philo->id - 1]);
    ft_print(philo->table, philo->id, "has taken a fork");
    pthread_mutex_lock(&philo->table->fork_mutex[philo->id % philo->table->number_of_philos]);
    ft_print(philo->table, philo->id, "has taken a fork");
    return (0);
}