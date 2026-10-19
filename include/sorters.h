/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 19:45:11 by vrouxel           #+#    #+#             */
/*   Updated: 2026/09/19 18:58:33 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTERS_H
# define SORTERS_H

# include "run.h"

void		bubblesort(t_run *run);
void		smallsort(t_run *run);
void		mediumsort(t_run *run);
void		radixsort(t_run *run);

#endif
