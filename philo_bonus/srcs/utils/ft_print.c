/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 03:22:07 by bahn              #+#    #+#             */
/*   Updated: 2021/11/24 01:20:31 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void    ft_print(t_table *table, int philo_id, char *action)
{
    pthread_mutex_lock(&table->print_mutex);
    if (died_philos == 0)
        printf("%d %d %s\n", time_ms() - table->begin_time, philo_id, action);
    pthread_mutex_unlock(&table->print_mutex);
}