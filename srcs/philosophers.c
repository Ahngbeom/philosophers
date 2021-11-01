/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:34:25 by bahn              #+#    #+#             */
/*   Updated: 2021/11/01 12:56:28 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosopher_init(t_table *table, int time_to_die, int must_eat)
{
	int id;

	table->philos = malloc(sizeof(t_philo *) * (table->number_of_philosophers + 1));
	if (table->philos == NULL)
		exit(EXIT_FAILURE);
	id = 0;
	while (id < table->number_of_philosophers)
	{
		table->philos[id] = malloc(sizeof(t_philo));
		table->philos[id]->table = table;
		table->philos[id]->id = id + 1;
		table->philos[id]->time_to_die = time_to_die;
		table->philos[id]->must_eat = must_eat;
		id++;
	}
	table->philos[id] = NULL;
}

t_philo *create_philosopher(int id, int time_to_die, int must_eat)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(EXIT_FAILURE);
	philo->id = id;
	philo->time_to_die = time_to_die;
	philo->must_eat = must_eat;
	return (philo);
}

void	death_check_philosophers(t_table *table)
{
	int i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (table->philos[i]->time_to_die <= 0)
		{
			gettimeofday(&table->ts_end, NULL);
			i = 0;
			while (i < table->number_of_philosophers)
			{
				pthread_detach(table->philos[i++]->pth_id);
			}
			table_status(table);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return ;
}