/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:36:50 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 16:07:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_node{
	int value;
	struct s_node *next;
}				t_node;

typedef struct	s_list{
	t_node *head;
	t_node *tail;
}				t_list;

t_list	*c_list(void);
t_node	*c_node(int value);
void	l_display(t_list *list);
void	l_addfront(t_list *list, t_node *node);
void	l_addback(t_list *list, t_node *node);
void	l_addafter(t_list *list, t_node *node1 , t_node *node2);
void	l_addbefore(t_list *list, t_node *node1, t_node *node2);
void	l_free(t_list *list);
void	l_delnode(t_list *list, t_node *node);
size_t	l_len(t_list *list);
t_list	*array_to_list(int *array, int len);

#endif