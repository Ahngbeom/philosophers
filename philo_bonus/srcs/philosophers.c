/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:02:55 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:16:31 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_philo *philosophers_init(t_table *table)
{
    t_philo *philos;
    int i;

    philos = malloc(sizeof(t_philo) * table->number_of_philos);
    i = -1;
    while (++i < table->number_of_philos)
    {
        philos[i].id = i + 1;
        philos[i].eat_count = 0;
        // philos[i].table = table;
        if (pthread_mutex_init(&philos[i].died_mutex, NULL) != 0)
            ft_error(table, "pthread mutex init");
    }
    return (philos);
}