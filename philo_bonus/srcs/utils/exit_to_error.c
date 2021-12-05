/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_to_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:22:54 by bahn              #+#    #+#             */
/*   Updated: 2021/12/04 22:31:26 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	exit_to_error(t_table *table, char *message)
{
	cleanup_table(table);
	printf("Error : %s\n", message);
	exit(EXIT_FAILURE);
}
